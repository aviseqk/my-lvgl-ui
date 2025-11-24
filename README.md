# Changes in the CMakeLists.txt for including my_lvgl_ui folder in the make process

# Add my UI files
file(GLOB MY_UI_SOURCES ${PROJECT_SOURCE_DIR}/my_lvgl_ui/*.c)
list(APPEND MAIN_SOURCES ${MY_UI_SOURCES})
# Add my assets
# added custom my_lvgl_ui/assets/*.c file, TODO: revisit to confirm if this the best way to include these
file(GLOB MY_ASSET_SOURCES ${PROJECT_SOURCE_DIR}/my_lvgl_ui/assets/*.c)
list(APPEND MAIN_SOURCES ${MY_ASSET_SOURCES})



