include $(THEOS)/makefiles/common.mk

TWEAK_NAME = SteamLinkDetection
SteamLinkDetection_FILES = src/Tweak.xm
SteamLinkDetection_FRAMEWORKS = UIKit CoreGraphics

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 Steam"

test: $(TWEAK_NAME) package install
