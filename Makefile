all: example_ios example_android

MAKE_STANDALONE_TOOLCHAIN=$(ANDROID_NDK_HOME)/build/tools/make-standalone-toolchain.sh

clean:
	-rm GypAndroid.mk
	-rm -rf libs/
	-rm -rf obj/
	-rm -rf build/
	-rm -rf build_ios/
	-xcodebuild -workspace example/objc/TextSort.xcworkspace -scheme TextSort -configuration 'Debug' -sdk iphonesimulator clean

# rule to lazily clone gyp
./deps/gyp:
	git clone --depth 1 https://chromium.googlesource.com/external/gyp.git ./deps/gyp

./deps/ninja/ninja:
	git clone --depth 1 --branch release https://github.com/martine/ninja.git ./deps/ninja
	sh -c 'cd ./deps/ninja && ./configure.py --bootstrap'

./deps/ndk-toolchain-arm:
	$(MAKE_STANDALONE_TOOLCHAIN) --arch=arm --platform=android-10 --install-dir=./deps/ndk-toolchain-arm

# we specify per-project root targets to prevent all of the targets from spidering out
out/Debug/build.ninja: ./deps/gyp example/libtextsort.gyp support-lib/support_lib.gyp example/example.djinni
	./example/run_djinni.sh
	NDK_TOOLCHAIN_DIR=$(PWD)/deps/ndk-toolchain-arm deps/gyp/gyp --depth=. -fninja-android -DOS=android -Icommon.gypi example/libtextsort.gyp --root-target=libtextsort_jni

./build_ios/example/libtextsort.xcodeproj: ./deps/gyp example/libtextsort.gyp support-lib/support_lib.gyp example/example.djinni
	./example/run_djinni.sh
	deps/gyp/gyp --depth=. -f xcode -DOS=ios --generator-output ./build_ios -Icommon.gypi example/libtextsort.gyp

example_ios: ./build_ios/example/libtextsort.xcodeproj
	xcodebuild -workspace example/objc/TextSort.xcworkspace \
           -scheme TextSort \
           -configuration 'Debug' \
           -sdk iphonesimulator

# this target implicitly depends on GypAndroid.mk since gradle will try to make it
example_android: GypAndroid.mk
	cd example/android/ && ./gradlew app:assembleDebug
	@echo "Apks produced at:"
	@python example/glob.py example/ '*.apk'

.PHONY: example_android example_ios clean all
