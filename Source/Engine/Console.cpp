#include "Console.h"

#include "ConsoleCommand.h"
#include "Engine.h"
#include "BitmapFont.h"
#include "Rectangle.h"
#include "KeyboardButtonEvent.h"

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

namespace BadEngine {
	Console::Console() :
		EventObserver(),
		m_active(false),
		m_font(NULL),
		m_currentCommand(),
		m_commands()
	{
	}
	
	Console::Console(Engine& engine, BitmapFont& font) :
		EventObserver(),
		m_active(false),
		m_font(&font),
		m_currentCommand(),
		m_commands()
	{
		engine.registerEventObserver(EVENT_KEYBOARD_BUTTON_DOWN, this);
	}
	
	Console::~Console()
	{
		if (m_font) {
			delete m_font;
		}
		
		map<string, ConsoleCommand*>::iterator it = m_commands.begin();
		for ( ; it != m_commands.end(); it++) {
			delete it->second;
		}
	}
	
	void Console::processCurrentCommand()
	{
		if (!m_currentCommand.empty()) {
			string command;
			string currentWord;
			vector<string> parameters;
		
			for (unsigned int i = 0; i < m_currentCommand.length(); i++) {
				if (m_currentCommand[i] == ' ') {
					if (currentWord.empty() == false) {
						if (command.empty()) {
							command = currentWord;
							currentWord.clear();
						} else {
							parameters.push_back(currentWord);
							currentWord.clear();
						}
					}
				} else {
					currentWord.push_back(m_currentCommand[i]);
				}
				if (i == (m_currentCommand.length() - 1) && currentWord.empty() == false) {
					if (command.empty()) {
						command = currentWord;
						currentWord.clear();
					} else {
						parameters.push_back(currentWord);
						currentWord.clear();
					}
				}
			}
		
			cout << "Command: " << command << endl;
			vector<string>::iterator it = parameters.begin();
			for ( ; it != parameters.end(); it++) {
				cout << "Parameter: " << *it << endl;
			}
			
			m_currentCommand.clear();
			
			map<string, ConsoleCommand*>::iterator commandIt = m_commands.find(command);
			if (commandIt != m_commands.end()) {
				commandIt->second->invoke(parameters);
			}
		}
	}
	
	void Console::registerCommand(string command, ConsoleCommand* action)
	{
		m_commands.insert(pair<string, ConsoleCommand*>(command, action));
	}
	
	void Console::setActive(bool active)
	{
		m_active = active;
	}
	
	void Console::activate()
	{
		m_active = true;
	}
	
	void Console::deactivate()
	{
		m_active = false;
	}
	
	void Console::draw(Engine& engine)
	{
		int width = engine.getScreenWidth();
		int height = engine.getScreenHeight() / 2;
		
		Rectangle background(0, 0, width, height);
		engine.drawRectangle(background, 0, 0, 0);
		
		Rectangle border(0, height, width, 1);
		engine.drawRectangle(border, 255, 255, 255);
		
		int currentCommandY = height - m_font->getHeight() - 1;
		ostringstream currentCommand;
		currentCommand << "]" << m_currentCommand << "_";
		m_font->drawText(1, currentCommandY, currentCommand);
	}
	
	void Console::onKeyboardButtonDown(KeyboardButtonEvent& event)
	{
		if (m_active) {
			if (event.getButton() == KEYBOARD_BUTTON_RETURN) {
				processCurrentCommand();
			} else if (event.getButton() == KEYBOARD_BUTTON_BACKSPACE) {
				if (m_currentCommand.length() > 0) {
					m_currentCommand.erase(m_currentCommand.length() - 1);
				}
			} else {
				switch (event.getButton()) {
					case KEYBOARD_BUTTON_SPACE:
					case KEYBOARD_BUTTON_COMMA:
					case KEYBOARD_BUTTON_MINUS:
					case KEYBOARD_BUTTON_PERIOD:
					case KEYBOARD_BUTTON_SLASH:
					case KEYBOARD_BUTTON_0:
					case KEYBOARD_BUTTON_1:
					case KEYBOARD_BUTTON_2:
					case KEYBOARD_BUTTON_3:
					case KEYBOARD_BUTTON_4:
					case KEYBOARD_BUTTON_5:
					case KEYBOARD_BUTTON_6:
					case KEYBOARD_BUTTON_7:
					case KEYBOARD_BUTTON_8:
					case KEYBOARD_BUTTON_9:
					case KEYBOARD_BUTTON_COLON:
					case KEYBOARD_BUTTON_SEMICOLON:
					case KEYBOARD_BUTTON_UNDERSCORE:
					case KEYBOARD_BUTTON_A:
					case KEYBOARD_BUTTON_B:
					case KEYBOARD_BUTTON_C:
					case KEYBOARD_BUTTON_D:
					case KEYBOARD_BUTTON_E:
					case KEYBOARD_BUTTON_F:
					case KEYBOARD_BUTTON_G:
					case KEYBOARD_BUTTON_H:
					case KEYBOARD_BUTTON_I:
					case KEYBOARD_BUTTON_J:
					case KEYBOARD_BUTTON_K:
					case KEYBOARD_BUTTON_L:
					case KEYBOARD_BUTTON_M:
					case KEYBOARD_BUTTON_N:
					case KEYBOARD_BUTTON_O:
					case KEYBOARD_BUTTON_P:
					case KEYBOARD_BUTTON_Q:
					case KEYBOARD_BUTTON_R:
					case KEYBOARD_BUTTON_S:
					case KEYBOARD_BUTTON_T:
					case KEYBOARD_BUTTON_U:
					case KEYBOARD_BUTTON_V:
					case KEYBOARD_BUTTON_W:
					case KEYBOARD_BUTTON_X:
					case KEYBOARD_BUTTON_Y:
					case KEYBOARD_BUTTON_Z:
						m_currentCommand.push_back(event.getButton());
						break;
					default:
						break;
				}
			}
		}
	}
};
