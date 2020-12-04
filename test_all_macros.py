import os

if __name__ == '__main__':
    os.system('rm sample11 sample13')
    os.system('g++ -o sample11 sample1.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread')
    os.system('g++ -DFAIL_ADD_TEST -o sample13 sample1.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread')
    os.system('./sample11 --gtest_output=xml:macro1.xml')
    os.system('./sample13 --gtest_output=xml:macro3.xml')
