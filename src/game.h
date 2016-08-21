//
// FILE: game.h
//

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "node.h"
#include "console.h"

namespace std
{
	class Game{

	public:
		Game() { head = new Node<string>;  console = new Console; }

		void play() const;

		void read();

		void write();

		void rounds(Node<string>* temp) const;

		void writeLoop(ofstream &os, Node<string>* temp);

		void treeCreate(queue<string> &info, Node<string>* curr);

	private:
		Node<string>* head;
		Console* console;
	};

	/// IMPLIMENTATION ///

	void Game::read(){
		string line;
		queue<string> lines;
		ifstream fs;
		string filename = console->PromptFilename("input");

		fs.open(filename);
		if (fs.is_open())
		{
			while (getline(fs, line))
			{
				lines.push(line);
			}
			fs.close();
		}
		Game::treeCreate(lines, head);
	}

	void Game::treeCreate(queue<string> &info, Node<string>* curr){
		if (info.front() == "$"){
			info.pop();
			curr->set_data(info.front());
			info.pop();
		}
		else{
			curr->set_data(info.front());
			info.pop();
			curr->create_left();
			curr->create_right();
			treeCreate(info, curr->getLeft());
			treeCreate(info, curr->getRight());
		}
	}

	void Game::write()
	{
		string filename = console->PromptFilename("output");
		ofstream os;
		os.open(filename);
		Game::writeLoop(os, head);
		os.close();
	}

	void Game::writeLoop(ofstream &os, Node<string>* temp)
	{
		if (temp != NULL)
		{
			os << temp->getData() << endl;
			writeLoop(os, temp->getLeft());
			writeLoop(os, temp->getRight());
		}
	}

	void Game::play() const{

		while (true){
			rounds(head);
			bool replay = console->PromptReplay();
			if (replay == false)
				break;
		}
	}

	void Game::rounds(Node<string>* temp) const{
		if (temp->getLeft() == NULL || temp->getRight() == NULL)
			console->VerifyAnswer(temp->getData());
		else{
			bool quest = console->PresentQuestion(temp->getData());
			if (quest == true)
				rounds(temp->getLeft());
			else
				rounds(temp->getRight());
		}
	}
}