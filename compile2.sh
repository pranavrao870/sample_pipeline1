rm sample21 sample22
g++ -o sample21 sample2.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a /usr/lib/libgmock.a /usr/lib/libgmock_main.a -lpthread
g++ -DFAIL_TEST -o sample22 sample2.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a /usr/lib/libgmock.a /usr/lib/libgmock_main.a -lpthread
