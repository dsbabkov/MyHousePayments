import qbs

CppApplication {
    consoleApplication: true
    files: [
        "src/dialogs/MainWindow.cpp",
        "src/dialogs/MainWindow.h",
        "src/dialogs/MainWindow.ui",
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
