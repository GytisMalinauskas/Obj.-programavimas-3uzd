#include "../headers/function.h"
#include "../headers/myVector.h"
#include <gtest/gtest.h>

int programos_veikimas;

TEST(Studento_Testavimas, Vector_Kartu_Su_Studentu) {
    Vector<studentas> studentai;
    for(int i = 0; i < 10; i++) {
        studentai.push_back(studentas());
    }
    EXPECT_EQ(studentai.size(), 10);
    EXPECT_EQ(studentai.capacity(), 16);
    studentai.shrink_to_fit();
    EXPECT_EQ(studentai.capacity(), 10);
    EXPECT_EQ(studentai.empty(), false);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Vector_Kartu_Su_Studentu_Konstruktorius) {
    Vector<studentas> studentas;
    EXPECT_EQ(studentas.size(), 0);
    EXPECT_EQ(studentas.capacity(), 0);
    EXPECT_EQ(studentas.empty(), true);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Kopijavimo_Konstruktorius) {
    Vector<studentas> studentas1;
    studentas1.push_back(studentas("Gytis", "Malinauskas"));
    Vector<studentas> studentas2(studentas1);
    EXPECT_EQ(studentas2.size(), 1);
    EXPECT_EQ(studentas2.capacity(), 1);
    EXPECT_EQ(studentas2.empty(), false);
    EXPECT_EQ(studentas1.size(), 1);
    EXPECT_EQ(studentas1.capacity(), 1);
    EXPECT_EQ(studentas1.empty(), false);
}

TEST(Studento_Testavimas, Studento_Default_Konstruktorius) {
    studentas studentas;
    EXPECT_EQ(studentas.getName(), "");
    EXPECT_EQ(studentas.getSurname(), "");
    EXPECT_EQ(studentas.ndSize(), 0);
    EXPECT_EQ(studentas.getEgz(), 0);
    EXPECT_EQ(studentas.getVid(), 0.0);
    EXPECT_EQ(studentas.getMed(), 0.0);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Move_Konstruktorius) {
    Vector<studentas> studentas1;
    studentas1.push_back(studentas("Gytis", "Malinauskas"));
    Vector<studentas> studentas2;
    studentas2 = std::move(studentas1);
    EXPECT_EQ(studentas2.size(), 1);
    EXPECT_EQ(studentas2.capacity(), 1);
    EXPECT_EQ(studentas2.empty(), false);
    EXPECT_EQ(studentas1.capacity(), 0);
    EXPECT_EQ(studentas1.size(), 0);
    EXPECT_EQ(studentas1.empty(), true);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Kopijavimo_Operatorius) {
    Vector<studentas> studentas1;
    studentas1.push_back(studentas("Gytis", "Malinauskas"));
    Vector<studentas> studentas2;
    studentas2 = studentas1;
    EXPECT_EQ(studentas2.size(), 1);
    EXPECT_EQ(studentas2.capacity(), 1);
    EXPECT_EQ(studentas2.empty(), false);
    EXPECT_EQ(studentas1.size(), 1);
    EXPECT_EQ(studentas1.capacity(), 1);
    EXPECT_EQ(studentas1.empty(), false);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, initializer_list) {
    Vector<studentas> studentas1 = {studentas("Gytis", "Malinauskas"), studentas("Petras", "Petraitis"), studentas("Marius", "Majonezius")};
    EXPECT_EQ(studentas1.size(), 3);
    EXPECT_EQ(studentas1.capacity(), 3);
    EXPECT_EQ(studentas1.empty(), false);
}

TEST(Vektoriaus_Member_Funkciju_Testavimas, Move_Operatorius) {
    Vector<studentas> studentas1;
    studentas1.push_back(studentas("Gytis", "Malinauskas"));
    studentas1.push_back(studentas("Petras", "Petraitis"));
    Vector<studentas> studentas2(std::move(studentas1));
    EXPECT_EQ(studentas2.size(), 2);
    EXPECT_EQ(studentas1.size(), 0);
    EXPECT_EQ(studentas2.capacity(), 2);
    EXPECT_EQ(studentas1.capacity(), 0);
    EXPECT_EQ(studentas2.empty(), false);
    EXPECT_EQ(studentas1.empty(), true);
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Front_Funkcija_studentas) {
    Vector<studentas> vector;
    studentas studentas1("Gytis", "Malinauskas");
    studentas studentas2("Marius", "Majonezius");
    vector.push_back(studentas1);
    vector.push_back(studentas2);
    EXPECT_EQ(vector.front().getName(), "Gytis");
    EXPECT_EQ(vector.front().getSurname(), "Malinauskas");
}

TEST(Vektoriaus_Element_Access_Funkciju_Testavimas, Back_Funkcija_studentas) {
    Vector<studentas> vector;
    studentas studentas1("Gytis", "Malinauskas");
    studentas studentas2("Marius", "Majonezius");
    vector.push_back(studentas1);
    vector.push_back(studentas2);
    EXPECT_EQ(vector.back().getName(), "Marius");
    EXPECT_EQ(vector.back().getSurname(), "Majonezius");
}

TEST(Vektoriaus_Capacity_Funkciju_Testavimas, Reserve_Funkcija) {
    Vector<studentas> studentas1;
    EXPECT_EQ(studentas1.capacity(), 0);
    studentas1.reserve(10);
    EXPECT_EQ(studentas1.capacity(), 10);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Clear_Funkcija) {
    Vector<studentas> studentas1;
    studentas1.push_back(studentas("Marius", "Majonezius"));
    studentas1.push_back(studentas("Gytis", "Malinauskas"));
    EXPECT_EQ(studentas1.size(), 2);
    studentas1.clear();
    EXPECT_EQ(studentas1.size(), 0);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Emplace_Funkcija_studentas) {
    Vector<studentas> vector;
    studentas studentas1("Gytis", "Malinauskas");
    studentas studentas2("Marius", "Majonezius");
    studentas studentas3("Petras", "Petraitis");

    vector.push_back(studentas1);
    vector.push_back(studentas2);
    vector.emplace(1, std::move(studentas3));

    EXPECT_EQ(vector.size(), 3);
    EXPECT_EQ(vector[0].getName(), "Gytis");
    EXPECT_EQ(vector[0].getSurname(), "Malinauskas");
    EXPECT_EQ(vector[1].getName(), "Petras");
    EXPECT_EQ(vector[1].getSurname(), "Petraitis");
    EXPECT_EQ(vector[2].getName(), "Marius");
    EXPECT_EQ(vector[2].getSurname(), "Majonezius");
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Pop_Back_Funkcija) {
    Vector<studentas> studentas1;
    studentas1.push_back(studentas("Gytis", "Malinauskas"));
    studentas1.push_back(studentas("Marius", "Majonezius"));
    studentas1.push_back(studentas("Petras", "Petraitis"));
    EXPECT_EQ(studentas1.size(), 3);
    studentas1.pop_back();
    EXPECT_EQ(studentas1.size(), 2);
    EXPECT_THROW(studentas1.at(2), std::out_of_range);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Resize_Funkcija) {
    Vector<studentas> studentas1;
    studentas1.push_back(studentas("Gytis", "Malinauskas"));
    studentas1.push_back(studentas("Marius", "Majonezius"));
    EXPECT_EQ(studentas1.size(), 2);
    studentas1.resize(4);
    studentas1.emplace(2, std::move(studentas("Petras", "Petraitis")));
    cout << studentas1.at(2);
    EXPECT_EQ(studentas1.size(), 5);
}

TEST(Vektoriaus_Modifiers_Funkciju_Testavimas, Swap_Funkcija) {
    Vector<studentas> studentas1;
    studentas1.reserve(10);
    studentas1.push_back(studentas("Gytis", "Malinauskas"));
    studentas1.push_back(studentas("Marius", "Majonezius"));
    Vector<studentas> studentas2;
    studentas2.push_back(studentas("Petras", "Petraitis"));
    studentas2.push_back(studentas("Ieva", "Ievaite"));
    studentas1.swap(studentas2);
    EXPECT_EQ(studentas1.size(), 2);
    EXPECT_EQ(studentas1.capacity(), 2);
    EXPECT_EQ(studentas2.size(), 2);
    EXPECT_EQ(studentas2.capacity(), 10);
    EXPECT_EQ(studentas1[0].getName(), "Petras");
    EXPECT_EQ(studentas1[0].getSurname(), "Petraitis");
    EXPECT_EQ(studentas1[1].getName(), "Ieva");
    EXPECT_EQ(studentas1[1].getSurname(), "Ievaite");

    EXPECT_EQ(studentas2[0].getName(), "Gytis");
    EXPECT_EQ(studentas2[0].getSurname(), "Malinauskas");
    EXPECT_EQ(studentas2[1].getName(), "Marius");
    EXPECT_EQ(studentas2[1].getSurname(), "Majonezius");
}


TEST(Studento_Testavimas, Studento_Parametirinis_Konstruktorius) {
    studentas studentas("Gytis", "Malinauskas");
    EXPECT_EQ(studentas.getName(), "Gytis");
    EXPECT_EQ(studentas.getSurname(), "Malinauskas");
    EXPECT_EQ(studentas.ndSize(), 0);
    EXPECT_EQ(studentas.getEgz(), 0);
    EXPECT_EQ(studentas.getVid(), 0.0);
    EXPECT_EQ(studentas.getMed(), 0.0);
}

TEST(Studento_Testavimas, Studento_Move_konstruktorius) {
    studentas studentas2("Gytis", "Malinauskas");
    studentas2.setMed(8.0);
    studentas studentas3(std::move(studentas2));
    EXPECT_EQ(studentas2.getName(), "");
    EXPECT_EQ(studentas2.getSurname(), "");
    EXPECT_EQ(studentas2.getMed(), 0.0);
    EXPECT_EQ(studentas3.getName(), "Gytis");
    EXPECT_EQ(studentas3.getSurname(), "Malinauskas");
    EXPECT_EQ(studentas3.getMed(), 8.0);
}

TEST(Studento_Testavimas, Studento_Copy_konstruktorius) {
    studentas studentas2("Gytis", "Malinauskas");
    studentas2.setMed(8.0);
    studentas studentas3(studentas2);
    EXPECT_EQ(studentas2.getName(), "Gytis");
    EXPECT_EQ(studentas2.getSurname(), "Malinauskas");
    EXPECT_EQ(studentas2.getMed(), 8.0);
    EXPECT_EQ(studentas3.getName(), "Gytis");
    EXPECT_EQ(studentas3.getSurname(), "Malinauskas");
    EXPECT_EQ(studentas3.getMed(), 8.0);
}

TEST(Studento_Testavimas, Studento_kopijavimo_operatorius) {
    studentas studentas2("Gytis", "Malinauskas");
    studentas2.setMed(8.0);
    studentas studentas3 = studentas2;
    EXPECT_EQ(studentas2.getName(), "Gytis");
    EXPECT_EQ(studentas2.getSurname(), "Malinauskas");
    EXPECT_EQ(studentas2.getMed(), 8.0);
    EXPECT_EQ(studentas3.getName(), "Gytis");
    EXPECT_EQ(studentas3.getSurname(), "Malinauskas");
    EXPECT_EQ(studentas3.getMed(), 8.0);
}

TEST(Studento_Testavimas, Studento_move_operatorius) {
    studentas studentas2("Gytis", "Malinauskas");
    studentas2.setMed(8.0);
    studentas studentas3 = std::move(studentas2);
    EXPECT_EQ(studentas2.getName(), "");
    EXPECT_EQ(studentas2.getSurname(), "");
    EXPECT_EQ(studentas2.getMed(), 0.0);
    EXPECT_EQ(studentas3.getName(), "Gytis");
    EXPECT_EQ(studentas3.getSurname(), "Malinauskas");
    EXPECT_EQ(studentas3.getMed(), 8.0);
}

TEST(Studento_Testavimas, Studento_Seteriai_ir_Geteriai) {
    studentas studentas;
    studentas.setName("Gytis");
    EXPECT_EQ(studentas.getName(), "Gytis");
    studentas.setSurname("Malinauskas");
    EXPECT_EQ(studentas.getSurname(), "Malinauskas");
    studentas.setND(10);
    studentas.setND(5);
    EXPECT_EQ(studentas.ndSize(), 2);
    EXPECT_EQ(studentas.getLastND(), 5);
    studentas.setEgz(10);
    EXPECT_EQ(studentas.getEgz(), 10);
    studentas.setVid(7.5);
    EXPECT_EQ(studentas.getVid(), 7.5);
    studentas.setMed(8.0);
    EXPECT_EQ(studentas.getMed(), 8.0);
    studentas.deleteLastNd();
    EXPECT_EQ(studentas.ndSize(), 1);
    EXPECT_EQ(studentas.getLastND(), 10);
}

int main(int argc, char** argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}