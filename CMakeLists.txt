set(TEST_CASE_SOURCES tests_Case.cpp ${PROJECT_SOURCE_DIR}/Case.cpp ${PROJECT_SOURCE_DIR}/Case.h)
add_executable (
    tests_Case
    ${TEST_CASE_SOURCES}
)
target_include_directories (tests_Case PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(
        tests_Case
        gtest_main
        gtest
        pthread
)

set(TEST_FILE_SOURCES tests_File.cpp ${PROJECT_SOURCE_DIR}/File.hpp ${PROJECT_SOURCE_DIR}/File.h
${PROJECT_SOURCE_DIR}/Case.cpp ${PROJECT_SOURCE_DIR}/Case.h
${PROJECT_SOURCE_DIR}/ListeCirculaire.hpp ${PROJECT_SOURCE_DIR}/ListeCirculaire.h)
add_executable (
    tests_File
    ${TEST_FILE_SOURCES}
)
target_include_directories (tests_File PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(
        tests_File
        gtest_main
        gtest
        pthread
)

set(TEST_LISTES_SOURCES tests_Listes.cpp ${PROJECT_SOURCE_DIR}/ListeDeCases.cpp ${PROJECT_SOURCE_DIR}/ListeDeCases.h
${PROJECT_SOURCE_DIR}/Case.cpp ${PROJECT_SOURCE_DIR}/Case.h)
add_executable (
    tests_Listes
    ${TEST_LISTES_SOURCES}
)
target_include_directories (tests_Listes PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(
        tests_Listes
        gtest_main
        gtest
        pthread
)

set(TEST_JEU_SOURCES tests_Jeu.cpp ${PROJECT_SOURCE_DIR}/JeuSerpentsEtEchelles.cpp ${PROJECT_SOURCE_DIR}/JeuSerpentsEtEchelles.h
${PROJECT_SOURCE_DIR}/Case.cpp ${PROJECT_SOURCE_DIR}/Case.h
${PROJECT_SOURCE_DIR}/ListeDeCases.cpp ${PROJECT_SOURCE_DIR}/ListeDeCases.h)
add_executable (
    tests_Jeu
    ${TEST_JEU_SOURCES}
)
target_include_directories (tests_Jeu PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(
        tests_Jeu
        gtest_main
        gtest
        pthread
)

include(GoogleTest)
gtest_discover_tests(tests_Case)
gtest_discover_tests(tests_File)
gtest_discover_tests(tests_Listes)
gtest_discover_tests(tests_Jeu)