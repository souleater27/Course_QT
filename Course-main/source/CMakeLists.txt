set(PROJECT_SOURCES
        main.cpp
        login.cpp
        login.h
        login.ui
        all.cpp
        all.h
        all.ui
        doctors.cpp
        doctors.h
        doctors.ui
        registration.cpp
        registration.h
        registration.ui
        user.cpp
        user.h
        user.ui
        zakaz.cpp
        zakaz.h
        zakaz.ui
)



add_executable(elect_reg ${PROJECT_SOURCES})

target_link_libraries(elect_reg PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Sql)