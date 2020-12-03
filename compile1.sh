rm sample11 sample12 sample13
g++ -o sample11 sample1.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread
g++ -DCAUSE_SEG_FAULT -o sample12 sample1.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread
g++ -DFAIL_ADD_TEST -o sample13 sample1.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread
