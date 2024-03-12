cc_library(
    name = "editor",
    srcs = [
        ":cursor.cpp",
        ":editor.cpp",
    ],
    hdrs = [
        ":editor.hpp",
        ":cursor.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//src/core/terminal:terminal",
        "//src/core/ui:ui",
        "//src/core/theme:theme",
        "//src/core/screen:screen",
    ],
)