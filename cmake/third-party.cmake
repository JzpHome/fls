include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929
)
FetchContent_MakeAvailable(googletest)
