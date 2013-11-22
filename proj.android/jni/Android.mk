LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/GameClasses/AppDelegate.cpp \
                   ../../Classes/GameClasses/Game.cpp \
                   ../../Classes/GameClasses/Player.cpp \
				   ../../Classes/GameClasses/Projectiles.cpp \
                   ../../Classes/GameClasses/Utils.cpp \
                   ../../Classes/Menus/HUD.cpp \
                   ../../Classes/Menus/GameOver.cpp \
                   ../../Classes/Enemies/EnemyKnight.cpp \
                   ../../Classes/Enemies/Enemy.cpp 



LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../Classes/Enemies \
					$(LOCAL_PATH)/../../Classes/Menus

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dxandroid_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,cocos2dx/platform/android)
