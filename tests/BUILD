cc_test(
    name = "tests",
    srcs = glob(["**/*.cpp"]),
    deps = [
        "//src/lib:IntersectingRectanglesLib",
        "@googletest//:gtest_main",
    ],
    data = ["//test-jsons:test-negative-values.json",
    	    "//test-jsons:test-negative-coordinates.json",
    	    "//test-jsons:test-morethan10.json",
    	    "//test-jsons:test-invalid-rects-key.json",
    	    "//test-jsons:test-invalid-rectangle-keys.json",
    	    "//test-jsons:test-invalid-data-types.json",
    	    "//test-jsons:test-4rects.json",
    	    "//test-jsons:test-invalid-json.json", 
    ],
)
