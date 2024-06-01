#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../headers/zmogus.h"
#include "../headers/studentas.h"
#include "../headers/function.h"
#include "../headers/myVector.h"

int programos_veikimas;

TEST_CASE("Vector and class tests", "[Vector][studentas]") {
    SECTION("Vector with studentas - Member Functions") {
        Vector<studentas> studentai;
        for (int i = 0; i < 10; i++) {
            studentai.push_back(studentas());
        }
        REQUIRE(studentai.size() == 10);
        REQUIRE(studentai.capacity() == 16);
        studentai.shrink_to_fit();
        REQUIRE(studentai.capacity() == 10);
        REQUIRE(studentai.empty() == false);
    }

    SECTION("Vector with studentas - Default Constructor") {
        Vector<studentas> studentas;
        REQUIRE(studentas.size() == 0);
        REQUIRE(studentas.capacity() == 0);
        REQUIRE(studentas.empty() == true);
    }

    SECTION("Copy Constructor") {
        Vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        Vector<studentas> studentas2(studentas1);
        REQUIRE(studentas2.size() == 1);
        REQUIRE(studentas2.capacity() == 1);
        REQUIRE(studentas2.empty() == false);
        REQUIRE(studentas1.size() == 1);
        REQUIRE(studentas1.capacity() == 1);
        REQUIRE(studentas1.empty() == false);
    }

    SECTION("Studentas Default Constructor") {
        studentas studentas;
        REQUIRE(studentas.getName() == "");
        REQUIRE(studentas.getSurname() == "");
        REQUIRE(studentas.ndSize() == 0);
        REQUIRE(studentas.getEgz() == 0);
        REQUIRE(studentas.getVid() == 0.0);
        REQUIRE(studentas.getMed() == 0.0);
    }

    SECTION("Move Constructor") {
        Vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        Vector<studentas> studentas2;
        studentas2 = std::move(studentas1);
        REQUIRE(studentas2.size() == 1);
        REQUIRE(studentas2.capacity() == 1);
        REQUIRE(studentas2.empty() == false);
        REQUIRE(studentas1.capacity() == 0);
        REQUIRE(studentas1.size() == 0);
        REQUIRE(studentas1.empty() == true);
    }

    SECTION("Copy Assignment Operator") {
        Vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        Vector<studentas> studentas2;
        studentas2 = studentas1;
        REQUIRE(studentas2.size() == 1);
        REQUIRE(studentas2.capacity() == 1);
        REQUIRE(studentas2.empty() == false);
        REQUIRE(studentas1.size() == 1);
        REQUIRE(studentas1.capacity() == 1);
        REQUIRE(studentas1.empty() == false);
    }

    SECTION("Initializer List") {
        Vector<studentas> studentas1 = {studentas("Gytis", "Malinauskas"), studentas("Petras", "Petraitis"), studentas("Marius", "Majonezius")};
        REQUIRE(studentas1.size() == 3);
        REQUIRE(studentas1.capacity() == 4);
        REQUIRE(studentas1.empty() == false);
    }

    SECTION("Move Assignment Operator") {
        Vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        studentas1.push_back(studentas("Petras", "Petraitis"));
        Vector<studentas> studentas2(std::move(studentas1));
        REQUIRE(studentas2.size() == 2);
        REQUIRE(studentas1.size() == 0);
        REQUIRE(studentas2.capacity() == 2);
        REQUIRE(studentas1.capacity() == 0);
        REQUIRE(studentas2.empty() == false);
        REQUIRE(studentas1.empty() == true);
    }

    SECTION("Front Function") {
        Vector<studentas> vector;
        studentas studentas1("Gytis", "Malinauskas");
        studentas studentas2("Marius", "Majonezius");
        vector.push_back(studentas1);
        vector.push_back(studentas2);
        REQUIRE(vector.front().getName() == "Gytis");
        REQUIRE(vector.front().getSurname() == "Malinauskas");
    }

    SECTION("Back Function") {
        Vector<studentas> vector;
        studentas studentas1("Gytis", "Malinauskas");
        studentas studentas2("Marius", "Majonezius");
        vector.push_back(studentas1);
        vector.push_back(studentas2);
        REQUIRE(vector.back().getName() == "Marius");
        REQUIRE(vector.back().getSurname() == "Majonezius");
    }

    SECTION("Reserve Function") {
        Vector<studentas> studentas1;
        REQUIRE(studentas1.capacity() == 0);
        studentas1.reserve(10);
        REQUIRE(studentas1.capacity() == 10);
    }

    SECTION("Clear Function") {
        Vector<studentas> studentas1;
        studentas1.push_back(studentas("Marius", "Majonezius"));
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        REQUIRE(studentas1.size() == 2);
        studentas1.clear();
        REQUIRE(studentas1.size() == 0);
    }

    SECTION("Emplace Function") {
        Vector<studentas> vector;
        studentas studentas1("Gytis", "Malinauskas");
        studentas studentas2("Marius", "Majonezius");
        studentas studentas3("Petras", "Petraitis");

        vector.push_back(studentas1);
        vector.push_back(studentas2);
        vector.emplace(1, std::move(studentas3));

        REQUIRE(vector.size() == 3);
        REQUIRE(vector[0].getName() == "Gytis");
        REQUIRE(vector[0].getSurname() == "Malinauskas");
        REQUIRE(vector[1].getName() == "Petras");
        REQUIRE(vector[1].getSurname() == "Petraitis");
        REQUIRE(vector[2].getName() == "Marius");
        REQUIRE(vector[2].getSurname() == "Majonezius");
    }

    SECTION("Pop Back Function") {
        Vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        studentas1.push_back(studentas("Marius", "Majonezius"));
        studentas1.push_back(studentas("Petras", "Petraitis"));
        REQUIRE(studentas1.size() == 3);
        studentas1.pop_back();
        REQUIRE(studentas1.size() == 2);
        REQUIRE_THROWS_AS(studentas1.at(2), std::out_of_range);
    }
    SECTION("Resize Function") {
        Vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        studentas1.push_back(studentas("Marius", "Majonezius"));
        REQUIRE(studentas1.size() == 2);
        studentas1.resize(4);
        studentas1.emplace(2, studentas("Petras", "Petraitis"));
        REQUIRE(studentas1.size() == 5);
    }

    SECTION("Swap Function") {
        Vector<studentas> studentas1;
        studentas1.reserve(10);
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        studentas1.push_back(studentas("Marius", "Majonezius"));
        Vector<studentas> studentas2;
        studentas2.push_back(studentas("Petras", "Petraitis"));
        studentas2.push_back(studentas("Ieva", "Ievaite"));
        studentas1.swap(studentas2);
        REQUIRE(studentas1.size() == 2);
        REQUIRE(studentas1.capacity() == 2);
        REQUIRE(studentas2.size() == 2);
        REQUIRE(studentas2.capacity() == 10);
        REQUIRE(studentas1[0].getName() == "Petras");
        REQUIRE(studentas1[0].getSurname() == "Petraitis");
        REQUIRE(studentas1[1].getName() == "Ieva");
        REQUIRE(studentas1[1].getSurname() == "Ievaite");

        REQUIRE(studentas2[0].getName() == "Gytis");
        REQUIRE(studentas2[0].getSurname() == "Malinauskas");
        REQUIRE(studentas2[1].getName() == "Marius");
        REQUIRE(studentas2[1].getSurname() == "Majonezius");
    }

    SECTION("Studentas Parameterized Constructor") {
        studentas studentas("Gytis", "Malinauskas");
        REQUIRE(studentas.getName() == "Gytis");
        REQUIRE(studentas.getSurname() == "Malinauskas");
        REQUIRE(studentas.ndSize() == 0);
        REQUIRE(studentas.getEgz() == 0);
        REQUIRE(studentas.getVid() == 0.0);
        REQUIRE(studentas.getMed() == 0.0);
    }

    SECTION("Studentas Move Constructor") {
        studentas studentas2("Gytis", "Malinauskas");
        studentas2.setMed(8.0);
        studentas studentas3(std::move(studentas2));
        REQUIRE(studentas2.getName() == "");
        REQUIRE(studentas2.getSurname() == "");
        REQUIRE(studentas2.getMed() == 0.0);
        REQUIRE(studentas3.getName() == "Gytis");
        REQUIRE(studentas3.getSurname() == "Malinauskas");
        REQUIRE(studentas3.getMed() == 8.0);
    }

    SECTION("Studentas Copy Constructor") {
        studentas studentas2("Gytis", "Malinauskas");
        studentas2.setMed(8.0);
        studentas studentas3(studentas2);
        REQUIRE(studentas2.getName() == "Gytis");
        REQUIRE(studentas2.getSurname() == "Malinauskas");
        REQUIRE(studentas2.getMed() == 8.0);
        REQUIRE(studentas3.getName() == "Gytis");
        REQUIRE(studentas3.getSurname() == "Malinauskas");
        REQUIRE(studentas3.getMed() == 8.0);
    }

    SECTION("Studentas Copy Assignment Operator") {
        studentas studentas2("Gytis", "Malinauskas");
        studentas2.setMed(8.0);
        studentas studentas3 = studentas2;
        REQUIRE(studentas2.getName() == "Gytis");
        REQUIRE(studentas2.getSurname() == "Malinauskas");
        REQUIRE(studentas2.getMed() == 8.0);
        REQUIRE(studentas3.getName() == "Gytis");
        REQUIRE(studentas3.getSurname() == "Malinauskas");
        REQUIRE(studentas3.getMed() == 8.0);
    }

    SECTION("Studentas Move Assignment Operator") {
        studentas studentas2("Gytis", "Malinauskas");
        studentas2.setMed(8.0);
        studentas studentas3 = std::move(studentas2);
        REQUIRE(studentas2.getName() == "");
        REQUIRE(studentas2.getSurname() == "");
        REQUIRE(studentas2.getMed() == 0.0);
        REQUIRE(studentas3.getName() == "Gytis");
        REQUIRE(studentas3.getSurname() == "Malinauskas");
        REQUIRE(studentas3.getMed() == 8.0);
    }

    SECTION("Studentas Setters and Getters") {
        studentas studentas;
        studentas.setName("Gytis");
        REQUIRE(studentas.getName() == "Gytis");
        studentas.setSurname("Malinauskas");
        REQUIRE(studentas.getSurname() == "Malinauskas");
        studentas.setND(10);
        studentas.setND(5);
        REQUIRE(studentas.ndSize() == 2);
        REQUIRE(studentas.getLastND() == 5);
        studentas.setEgz(10);
        REQUIRE(studentas.getEgz() == 10);
        studentas.setVid(7.5);
        REQUIRE(studentas.getVid() == 7.5);
        studentas.setMed(8.0);
        REQUIRE(studentas.getMed() == 8.0);
        studentas.deleteLastNd();
        REQUIRE(studentas.ndSize() == 1);
        REQUIRE(studentas.getLastND() == 10);
    }
}
TEST_CASE("Vector tests", "[Vector]") {
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
        REQUIRE(v.capacity() == 4);
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
        REQUIRE(v[0] == 1);
        REQUIRE(v.capacity() == 1);
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
        v.erase(pirmas_elementas_salinimui, paskutinis_elementas_salinimui);

        REQUIRE(v.size() == 3);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 4);
        REQUIRE(v[2] == 5);
    }
}
