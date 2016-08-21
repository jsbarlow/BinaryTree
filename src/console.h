//
// FILE: console.h
//

#include <iostream>
#include <string>

namespace std
{
	class Console{

	public:
		Console(){}

		string PromptFilename(string Filename);

		bool PresentQuestion(string question);

		void VerifyAnswer(string answer);

		bool PromptReplay();
	};

	string Console::PromptFilename(string filename){
		string file;
		cout << "What is your " << filename << " filepath?" << endl;
		cin >> file;
		return file;
	}

	bool Console::PresentQuestion(string question){
		string ans;
		cout << question << endl;
		cout << "Answer 'yes' or 'no'." << endl;
		cin >> ans;
		while (true){
			if (ans == "yes")
				return true;
			else if (ans == "no")
				return false;
			else{
				cout << "Invalid input. Try again." << endl;
				cin >> ans;
			}
		}
	}

	void Console::VerifyAnswer(string answer){
		string ans;
		cout << "Were you thinking of " << answer << "?" << endl;
		cout << "Answer 'yes' or 'no'." << endl;
		cin >> ans;
		while (true){
			if (ans == "yes")
				break;
			else if (ans == "no")
				break;
			else{
				cout << "Invalid input. Try again." << endl;
				cin >> ans;
			}
		}
	}

	bool Console::PromptReplay(){
		string ans;
		cout << "Would you like to play again?" << endl;
		cout << "Answer 'yes' or 'no'." << endl;
		cin >> ans;
		while (true){
			if (ans == "yes")
				return true;
			else if (ans == "no")
				return false;
			else{
				cout << "Invalid input. Try again." << endl;
				cin >> ans;
			}
		}
	}
}