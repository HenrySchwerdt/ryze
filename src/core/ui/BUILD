cc_library(
    name = "ui",
    srcs = [
        ":command_bar.cpp",
        ":status_bar.cpp",
        ":text_buffer.cpp"
    ],
    hdrs = [
        ":status_bar.hpp",
        ":command_bar.hpp",
        ":text_buffer.hpp",
        ":ui.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//src/core/terminal:terminal",
        "//src/core/screen:screen",
        "//src/core/theme:theme",
    ],
)