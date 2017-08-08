import qbs

CppApplication {
    consoleApplication: true
    files: [
        "src/core/ApplicationSettings.h",
        "src/dialogs/MainWindow.cpp",
        "src/dialogs/MainWindow.h",
        "src/dialogs/MainWindow.ui",
        "src/dialogs/SettingsDialog.cpp",
        "src/dialogs/SettingsDialog.h",
        "src/dialogs/SettingsDialog.ui",
        "src/main.cpp",
    ]

    cpp.includePaths: ["src"]

    Depends {
        name: "Qt"
        submodules: ["core", "gui", "widgets"]
    }

    Group {
        fileTagsFilter: product.type
        qbs.install: true
    }
}
