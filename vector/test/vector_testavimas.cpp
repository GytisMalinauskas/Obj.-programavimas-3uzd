#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../headers/myVector.h"

TEST_CASE("Vektoriaus Member Funkciju Testavimas", "[Vector]") {
    
    SECTION("konstruktorius") {
        Vector<int> v;
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == 0);
        REQUIRE(v.empty() == true);
    }

    SECTION("Kopijavimo Konstruktorius") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        Vector<int> v2(v);
        REQUIRE(v2.size() == 2);
        REQUIRE(v2.capacity() == 2);
        REQUIRE(v2.empty() == false);
        REQUIRE(v2[0] == 1);
        REQUIRE(v2[1] == 2);
        REQUIRE(v.size() == 2);
        REQUIRE(v.capacity() == 2);
        REQUIRE(v.empty() == false);
    }

    SECTION("Move Konstruktorius") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        Vector<int> v2;
        v2 = std::move(v);
        REQUIRE(v2.size() == 2);
        REQUIRE(v2.capacity() == 2);
        REQUIRE(v2.empty() == false);
        REQUIRE(v.capacity() == 0);
        REQUIRE(v.size() == 0);
        REQUIRE(v.empty() == true);
        REQUIRE(v2[0] == 1);
        REQUIRE(v2[1] == 2);
    }

    SECTION("Kopijavimo Operatorius") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        Vector<int> v2;
        v2 = v;
        REQUIRE(v2.size() == 2);
        REQUIRE(v2.capacity() == 2);
        REQUIRE(v2.empty() == false);
        REQUIRE(v2[0] == 1);
        REQUIRE(v2[1] == 2);
        REQUIRE(v.size() == 2);
        REQUIRE(v.capacity() == 2);
        REQUIRE(v.empty() == false);
    }

    SECTION("initializer list") {
        Vector<std::string> v = {"Tomas", "Jonas", "Petras"};
        REQUIRE(v.size() == 3);
        REQUIRE(v.capacity() == 3);
        REQUIRE(v.empty() == false);
        REQUIRE(v[0] == "Tomas");
        REQUIRE(v[1] == "Jonas");
        REQUIRE(v[2] == "Petras");
    }

    SECTION("Move Operatorius") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        Vector<int> v2(std::move(v));
        REQUIRE(v2.size() == 2);
        REQUIRE(v.size() == 0);
        REQUIRE(v2.capacity() == 2);
        REQUIRE(v.capacity() == 0);
        REQUIRE(v2.empty() == false);
        REQUIRE(v.empty() == true);
    }

    SECTION("Operatorius Kvadratiniu Sklaustu") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
    }

    SECTION("At Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v.at(0) == 1);
        REQUIRE(v.at(1) == 2);
        REQUIRE_THROWS_AS(v.at(2), std::out_of_range);
    }

    SECTION("Front Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v.front() == 1);
    }

    SECTION("Back Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v.back() == 2);
    }

    SECTION("Data Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v.data2()[0] == 1);
        REQUIRE(v.data2()[1] == 2);
    }

    SECTION("Begin Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(*v.begin() == 1);
    }

    SECTION("End Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(*(v.end() - 1) == 2);
    }

    SECTION("Capacity Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v.capacity() == 2);
    }

    SECTION("Size Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v.size() == 2);
        v.push_back(3);
        REQUIRE(v.size() == 3);
    }

    SECTION("Empty Funkcija") {
        Vector<int> v;
        REQUIRE(v.empty() == true);
        v.push_back(1);
        REQUIRE(v.empty() == false);
    }

    SECTION("Reserve Funkcija") {
        Vector<int> v;
        REQUIRE(v.capacity() == 0);
        v.reserve(10);
        REQUIRE(v.capacity() == 10);
    }

    SECTION("Shrink to fit Funkcija") {
        Vector<int> v;
        v.reserve(10);
        v.push_back(1);
        v.push_back(2);
        v.shrink_to_fit();
        REQUIRE(v.capacity() == 2);
    }

    SECTION("Assign Funkcija") {
        Vector<int> v;
        v.assign(10, 5);
        REQUIRE(v.size() == 10);
        for (int i = 0; i < 10; i++) {
            REQUIRE(v[i] == 5);
        }
    }

    SECTION("Clear Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v.size() == 2);
        v.clear();
        REQUIRE(v.size() == 0);
    }

    SECTION("Push Back Funkcija") {
        Vector<int> v;
        v.push_back(1);
        REQUIRE(v.size() == 1);
        REQUIRE(v.capacity() == 1);
        REQUIRE(v[0] == 1);
        v.push_back(2);
        REQUIRE(v.size() == 2);
        REQUIRE(v.capacity() == 2);
        REQUIRE(v[1] == 2);
        v.push_back(3);
        REQUIRE(v.size() == 3);
        REQUIRE(v.capacity() == 4);
        REQUIRE(v[2] == 3);
    }

    SECTION("Emplace Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.emplace(1, 3);
        REQUIRE(v.size() == 3);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 3);
        REQUIRE(v[2] == 2);
    }

    SECTION("Emplace Back Funkcija") {
        Vector<int> v;
        v.emplace_back(1);
        REQUIRE(v.size() == 1);
        REQUIRE(v.capacity() == 1);
        REQUIRE(v[0] == 1);
        v.emplace_back(2);
        REQUIRE(v.size() == 2);
        REQUIRE(v.capacity() == 2);
        REQUIRE(v[1] == 2);
        v.emplace_back(3);
        REQUIRE(v.size() == 3);
        REQUIRE(v.capacity() == 4);
        REQUIRE(v[2] == 3);
    }

    SECTION("Pop Back Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        REQUIRE(v.size() == 3);
        v.pop_back();
        REQUIRE(v.size() == 2);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
        REQUIRE_THROWS_AS(v.at(2), std::out_of_range);
    }

    SECTION("Resize Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        REQUIRE(v.size() == 2);
        v.resize(4);
        REQUIRE(v.size() == 4);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 0);
        REQUIRE(v[3] == 0);
    }

    SECTION("Swap Funkcija") {
        Vector<int> v1;
        v1.reserve(10);
        v1.push_back(1);
        v1.push_back(2);
        Vector<int> v2;
        v2.push_back(3);
        v2.push_back(4);
        v1.swap(v2);
        REQUIRE(v1.size() == 2);
        REQUIRE(v1.capacity() == 2);
        REQUIRE(v2.size() == 2);
        REQUIRE(v2.capacity() == 10);
        REQUIRE(v1[0] == 3);
        REQUIRE(v1[1] == 4);
        REQUIRE(v2[0] == 1);
        REQUIRE(v2[1] == 2);
    }

    SECTION("Insert Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.insert(v.begin() + 1, 3);
        REQUIRE(v.size() == 3);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 3);
        REQUIRE(v[2] == 2);
    }

    SECTION("Erase Funkcija Pagal Pozicija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.erase(1);
        REQUIRE(v.size() == 2);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 3);
    }

    SECTION("Erase Funkcija") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        int* pirmas_elementas_salinimui = v.data2() + 1;
        int* paskutinis_elementas_salinimui = v.data2() + 3;
        int* result = v.erase(pirmas_elementas_salinimui, paskutinis_elementas_salinimui);

        REQUIRE(v.size() == 3);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 4);
        REQUIRE(v[2] == 5);
    }
}
