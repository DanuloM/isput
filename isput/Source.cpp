#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
#include <Windows.h>
#include <sstream>
using namespace std;

class test {
	string login;
	string password;
	string name;
	string surname;
	string phone;
	string address;
public:
	test() {
		login = "";
		password = "";
		name = "";
		address = "";
		phone = "";
		surname = "";
	}
	test(string login, string password, string name, string surname, string phone, string address) {
		this->login = login;
		this->password = password;
		this->name = name;
		this->surname = surname;
		this->phone = phone;
		this->address = address;
	}
	void set() {
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter you phone number: ";
		cin >> phone;
		cout << "Enter your address: ";
		cin >> address;
		cout << "Enter login: ";
		cin >> login;
		cout << "Enter password: ";
		cin >> password;
	}
	int countOfLines(string path) {
		string line;
		int number_of_lines=0;
		ifstream myfile(path);

		if (myfile.is_open()) {
			while (!myfile.eof()) {
				getline(myfile, line);
				number_of_lines++;
			}
			myfile.close();
		}
		return number_of_lines;
	}
	bool CheckWord(string filename, string search)
	{
		int offset;
		string line;
		fstream fs;
		fs.open(filename);
		if (fs.is_open())
		{
			while (!fs.eof())
			{
				string a;
				fs >> a;
				if (a == search) {
					cout << "Found"<<endl;
					return true;
				}
				a.clear();
			}
			fs.close();
		}
		else
			cout << "Unable to open this file." << endl;

		return false;
	}
	void reg(string path,int number_of_lines) {
		fstream fs;
		fs.open(path);
		if (number_of_lines < 6) {
			cout << "Enter you login: ";
			cin >> login;
			cout << "Enter your password: ";
			cin >> password;
			fs.seekg(0, ios::end);
			fs <<"Login: " << login << endl;
			fs << "Password: " << password<<endl;
		}
		else {
			cout << "U cant register anymore, u alreay have 3 accounts!"<<endl;
		}
		fs.close();
	}

	bool log(string path) {
		fstream fs;
		string a;
		string log="Login:";
		fs.open(path);
		if (!fs.is_open()) {
			cout << "Cant open the file!";
		}
		else {
			cout << "Enter login: ";
			(cin>>a).get();
			log += a;
			if (CheckWord(path, log) == true) {
				cout << "Nice!"<<endl;
				return true;
			}
		}
		cout << "Not found!" << endl;
		return false;
	}

	bool pw(string path) {
		fstream fs;
		string a;
		string log = "Password:";
		fs.open(path);
		if (!fs.is_open()) {
			cout << "Cant open the file!";
		}
		else {
			cout << "Enter password: ";
			(cin >> a).get();
			log += a;
			if (CheckWord(path, log) == true) {
				cout << "Nice!" << endl;
				return true;
			}
		}
		cout << "Not found!" << endl;
		return false;
	}
};

int loginorregMenu() {
	int choice;
	cout << "Login or register menu" << endl;
	cout << "0-back" << endl;
	cout << "1-login"<<endl;
	cout << "2-register"<<endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

int adminMenu() {
	int choice;
	cout << "Admin menu" << endl;
	cout << "0-back" << endl;
	cout << "1-showgrades history" << endl;
	cout << "2-showgrades geography" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}
int testMenu() {
	int choice;
	cout << "Test menu" << endl;
	cout << "0-back" << endl;
	cout << "1-start test History" << endl;
	cout << "2-start test Geography" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

int mainMenu() {
	int choice;
	cout << "Main menu" << endl;
	cout << "0-exit"<<endl;
	cout << "1-Admin"<<endl;
	cout << "2-Test"<<endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}


class history {
	int points = 0;
	string answer;

public:
	history() {
		points = 0;
		answer = "";
	}
	history(string answer, int points) {
		this->points = points;
		this->answer = answer;
	}
	void eventH() {
		system("cls");
		cout << "Every question 2 points!" << endl;
		cout << "Are you ready?" << endl;
		cout << "The test will start in 5 seconds" << endl;
		Sleep(5000);
		system("cls");
		first_q();
		second_q();
		third_q();
		fourth_q();
		fiveth_q();
		sixth_q();
		system("cls");
		cout << "The test is over" << endl;
		cout << "Wait for results..." << endl;
		Sleep(2000);
		system("cls");
		points *= 2;
		cout << "Your grade: " << points;
		Sleep(3000);
		system("cls");
	}

	string addQ() {
		string q;
		cout << "Enter your question: ";
		cin >> q;
		return q;
	}
	bool qAdded() {
		return true;
	}
	string addAnsw() {
		string a;
		cout << "Enter the answer";
		cin >> a;
		return a;
	}
	int addedQuestion(bool added) {
		string a;
		if (added == true) {
			cout << addQ();
			if (a == addAnsw()) {
				cout << "Good job!";
				points++;
			}
			else {
				cout << "You are wrong !";
			}
		}
		return points;
	}
	int first_q() {
		cout << "First question: " << endl;
		cout << "When Ukraine gained independence? (year)";
		cin >> answer;
		if (answer == "1991") {
			cout << "Good job u are right!" << endl;
			points++;
		}
		else {
			cout << "You are wrong!" << endl;
			return points;
		}
		return points;
	}
	int second_q() {
		cout << "Second question: " << endl;
		cout << "When the second world war started? (year)";
		cin >> answer;
		if (answer == "1939") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int third_q() {
		cout << "Third question: " << endl;
		cout << "when the war started in Ukraine (year)";
		cin >> answer;
		if (answer == "2022") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int fourth_q() {
		cout << "Fourth question: " << endl;
		cout << "First president of ukraine? (only surname (big letter first!))";
		cin >> answer;
		if (answer == "Kravchuk") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int fiveth_q() {
		cout << "Fiveth question: " << endl;
		cout << "when the queen of england died? (year)";
		cin >> answer;
		if (answer == "2022") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int sixth_q() {
		cout << "Sixth question: " << endl;
		cout << "when Yaroslav Mudriy was born? (year)";
		cin >> answer;
		if (answer == "978") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}

	int getGrade()const {
		return points;
	}

};

class geography{
	int points=0;
	string answer;

public:

	geography() {
		points = 0;
		answer = "";
	}
	geography(string answer, int points) {
		this->points = points;
		this->answer = answer;
	}
	void eventG() {
		system("cls");
		cout << "Every question 2 points!" << endl;
		cout << "Are you ready?" << endl;
		cout << "The test will start in 5 seconds" << endl;
		Sleep(5000);
		system("cls");
		first_q();
		second_q();
		third_q();
		fourth_q();
		fiveth_q();
		sixth_q();
		system("cls");
		cout << "The test is over" << endl;
		cout << "Wait for results..." << endl;
		Sleep(2000);
		system("cls");
		points *= 2;
		cout << "Your grade: " << points;
		Sleep(3000);
		system("cls");
	}
	string addQ() {
		string q;
		cout << "Enter your question: ";
		cin >> q;
		return q;
	}
	bool qAdded() {
		return true;
	}
	string addAnsw() {
		string a;
		cout << "Enter the answer";
		cin >> a;
		return a;
	}
	int addedQuestion(bool added) {
		string a;
		if (added == true) {
			cout << addQ();
			if (a == addAnsw()) {
				cout << "Good job!";
				points++;
			}
			else {
				cout << "You are wrong !";
			}
		}
		return points;
	}
	int first_q() {
		cout << "First question: " << endl;
		cout << "Country with most population?";
		cin >> answer;
		if (answer == "china"|| answer=="China") {
			cout << "Good job u are right!" << endl;
			points++;
		}
		else {
			cout << "You are wrong!" << endl;
			return points;
		}
		return points;
	}
	int second_q() {
		cout << "Second question: " << endl;
		cout << "Who is president of Ukraine?(Only surname and big letter first)";
		cin >> answer;
		if (answer == "Zelenskiy") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int third_q() {
		cout << "Third question: " << endl;
		cout << "The most rich in the world country?";
		cin >> answer;
		if (answer == "usa"|| answer=="Usa"|| answer=="USA") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int fourth_q() {
		cout << "Fourth question: " << endl;
		cout << "Smallest country in the world?";
		cin >> answer;
		if (answer == "Vatican" || answer=="Vatican city" || answer=="Vatican City") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int fiveth_q() {
		cout << "Fiveth question: " << endl;
		cout << "National italian dish?";
		cin >> answer;
		if (answer == "pasta" || answer=="pizza") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int sixth_q() {
		cout << "Sixth question: " << endl;
		cout << "Capital of spain?";
		cin >> answer;
		if (answer == "Madrid") {
			cout << "Good job u are right!";
			points++;
		}
		else {
			cout << "You are wrong!";
			return points;
		}
		return points;
	}
	int getGrade() {
		return points;
	}
};

class admin {
	string login;
	string password;
public:
	admin() {
		login = "";
		password = "";
	}
	admin(string login, string password) {
		this->login = login;
		this->password = password;
	}
	void reg(string path, int number_of_lines) {
		fstream fs;
		fs.open(path);
		if (number_of_lines < 2) {
			cout << "Enter you login: ";
			cin >> login;
			cout << "Enter your password: ";
			cin >> password;
			fs.seekg(0, ios::end);
			fs << "Login: " << login << endl;
			fs << "Password: " << password << endl;
		}
		else {
			cout << "U cant register anymore, u alreay have account!"<<endl;
		}
		fs.close();
	}
	int countOfLines(string path) {
		string line;
		int number_of_lines = 0;
		ifstream myfile(path);

		if (myfile.is_open()) {
			while (!myfile.eof()) {
				getline(myfile, line);
				number_of_lines++;
			}
			myfile.close();
		}
		return number_of_lines;
	}
	bool CheckWord(string filename, string search)
	{
		int offset;
		string line;
		fstream fs;
		fs.open(filename);
		if (fs.is_open())
		{
			while (!fs.eof())
			{
				string a;
				fs >> a;
				if (a == search) {
					cout << "Found" << endl;
					return true;
				}
				a.clear();
			}
			fs.close();
		}
		else
			cout << "Unable to open this file." << endl;

		return false;
	}
	bool pw(string path) {
		fstream fs;
		string a;
		string log = "Password:";
		fs.open(path);
		if (!fs.is_open()) {
			cout << "Cant open the file!";
		}
		else {
			cout << "Enter password:";
			(cin >> a).get();
			log += a;
			if (CheckWord(path, log) == true) {
				cout << "Nice!" << endl;
				return true;
			}
		}
		cout << "Not found!" << endl;
		return false;
	}
	bool log(string path) {
		fstream fs;
		string a;
		string log = "Login:";
		fs.open(path);
		if (!fs.is_open()) {
			cout << "Cant open the file!";
		}
		else {
			cout << "Enter login:";
			(cin >> a).get();
			log += a;
			if (CheckWord(path, log) == true) {
				cout << "Nice!"<<endl;
				return true;
			}
		}
		cout << "Not found!" << endl;
		return false;
	}
	void showGradesH(vector<int> h) {
		if (h.size() == 0) {
			cout << "No grades yet!"<<endl;
		}
		else {
			cout << "Grades: " << endl;
			for (int i = 0; i < h.size(); i++) {
				cout << h[i] << endl;
			}
		}
	}
	void showGradesG(vector<int> g) {
		if (g.size()==0) {
			cout << "No grades yet!"<<endl;
		}
		else {
			cout << "Grades: " << endl;
			for (int i = 0; i < g.size(); i++) {
				cout << g[i] << endl;
			}
		}
	}
};


int main() {
	history h;
	geography g;
	admin a;
	test t;
	string path = "test.txt";
	string path1 = "admin.txt";
	vector<int> g1;
	vector<int> h1;
	do {
		bool q1 = true;
		bool q = true;
		int choice1 = mainMenu();
		switch (choice1) {
			case 0:
				exit(0);
				break;
			case 1:
				system("cls");
				do {
					int choice = loginorregMenu();
					system("cls");
					switch (choice) {
						case 0:
							q = false;
							break;
						case 1:
							if (a.log(path1) == true && a.pw(path1)) {
								do {
									int choice = adminMenu();
									system("cls");
									switch (choice) {
										case 0:
											q = false;
											break;
										case 1:
											a.showGradesH(h1);
											break;
										case 2:
											a.showGradesG(g1);
									}
								} while (q != false);
							}
							break;
						case 2:
							a.reg(path1, a.countOfLines(path1));
							break;
					}
				} while (q != false);
				break;
			case 2:
				system("cls");
				do {
					int choice = loginorregMenu();
					system("cls");
					switch (choice) {
					case 0:
						q = false;
						break;
					case 1:
						if (t.log(path) == true && t.pw(path) == true) {
							do {
								int choice = testMenu();
								system("cls");
								switch (choice) {
								case 0:
									q = false;
									break;
								case 1:
									h.eventH();
									h1.push_back(h.getGrade());
									break;
								case 2:
									g.eventG();
									g1.push_back(g.getGrade());
									break;
								}
							} while (q != false);
						}
						break;
					case 2:
						t.reg(path, t.countOfLines(path));
						break;
					}
				} while (q != false);
				break;
		};
	} while (true);

	return 0;
}