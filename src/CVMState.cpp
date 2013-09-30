/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include <iostream>
#include "CVMState.h"
#include <string>
#include <sstream>

using std::string;
using std::endl;
using std::cout;
using std::stringstream;

namespace com_adarwin_simulation {
    CVMState::CVMState() {
    }

    CVMState::CVMState(int quarters, int dimes, int nickels) :
                       currentQuarters(0), currentDimes(0), currentNickels(0),
                       totalQuarters(quarters), totalDimes(dimes),
                       totalNickels(nickels), changeSelected(false) {}

    CVMState::CVMState(int currentQuarters, int currentDimes,
                       int currentNickels, int totalQuarters, int totalDimes,
                       int totalNickels, bool changeSelected)
                       :
                       currentQuarters(currentQuarters),
                       currentDimes(currentDimes),
                       currentNickels(currentNickels),
                       totalQuarters(totalQuarters),
                       totalDimes(totalDimes),
                       totalNickels(totalNickels),
                       changeSelected(changeSelected) {}

    int CVMState::getCurrentNickels() { return currentNickels; }
    int CVMState::getCurrentDimes() { return currentDimes; }
    int CVMState::getCurrentQuarters() { return currentQuarters; }
    int CVMState::getTotalQuarters() { return totalQuarters; }
    int CVMState::getTotalDimes() { return totalDimes; }
    int CVMState::getTotalNickels() { return totalNickels; }

    bool CVMState::isChangeSelected() { return changeSelected; }

    void CVMState::incrementCurrentNickels() {
        currentNickels++;
    }
    void CVMState::incrementCurrentDimes() {
        currentDimes++;
    }
    void CVMState::incrementCurrentQuarters() {
        currentQuarters++;
    }
    void CVMState::setChangeSelected(bool value) {
        changeSelected = value;
    }
    void CVMState::setWaiting(bool value) {
        waiting = value;
    }
    int CVMState::getTotalCents() {
        return 5*totalNickels + 10*totalDimes + 25*totalQuarters;
    }
    int CVMState::getCurrentCents() {
        return 5*currentNickels + 10*currentDimes + 25*currentQuarters;
    }
    bool CVMState::moveCentsToMainStorage(int cents) {
        int* changeArray = new int[3];
        changeArray = makeChange(cents, currentQuarters,
                                 currentDimes, currentNickels, changeArray);
        if (changeArray == NULL) {
            delete changeArray;
            return false;
        } else {
            moveChangeToMainStorage(changeArray);
            delete changeArray;
            return true;
        }
    }
    bool CVMState::moveCentsToTransactionStorage(int cents) {
        int* changeArray = new int[3];
        changeArray = makeChange(cents, totalQuarters,
                                 totalDimes, totalNickels, changeArray);
        if (changeArray == NULL) {
            delete changeArray;
            return false;
        } else {
            moveChangeToTransactionStorage(changeArray);
            delete changeArray;
            return true;
        }
    }
    bool CVMState::removeCents(int cents) {
        return moveCurrentCents(cents, false);
    }

    bool CVMState::moveCurrentCents(int cents, bool toMainStorage) {
        int quartersToMove = 0, dimesToMove = 0, nickelsToMove = 0;
        while (cents >= 25 && currentQuarters > 0) {
            cents -= 25;
            currentQuarters--;
            if (toMainStorage) quartersToMove++;
        }
        while (cents >= 10 && currentDimes > 0) {
            cents -= 10;
            currentDimes--;
            if (toMainStorage) dimesToMove++;
        }
        while (cents >= 5 && currentNickels > 0) {
            cents -= 5;
            currentNickels--;
            if (toMainStorage) nickelsToMove++;
        }
        if (cents > 0) {
            return false;
        } else {
            totalQuarters += quartersToMove;
            totalDimes += dimesToMove;
            totalNickels += nickelsToMove;
            return true;
        }
    }
    int CVMState::numDigits(int number) {
        int numDigits = 0;
        if (number == 0) numDigits++;
        while (number > 0) {
            number /= 10;
            numDigits++;
        }
        return numDigits;
    }
    string CVMState::getRightPadding(string inputString, int totalSpace) {
        stringstream ss;
        int stringSize = inputString.size();
        for (int i = totalSpace-stringSize; i > 0; i--) {
            ss << " ";
        }
        return ss.str();
    }
    string CVMState::getStringLine(string coinType, int current, int total) {
        stringstream ss, currentSS, totalSS;
        currentSS << coinType << current;
        string currentString = currentSS.str();
        totalSS << coinType << total;
        string totalString = totalSS.str();

        ss << "| " << currentString << getRightPadding(currentString, 19);
        ss << " | " << totalString << getRightPadding(totalString, 19);
        ss << " |" << endl;
        /*
        int stringSize = coinType.size();
        ss << "| " << coinType << current;
        int digits = numDigits(current);
        for (int i = 19-stringSize; i > digits; i--) {
            ss << " ";
        }
        ss <<                      " | " << coinType << total;
        digits = numDigits(total);
        for (int i = 19-stringSize; i > digits; i--) {
            ss << " ";
        }
        ss <<                                          " |" << endl;
        */
        return ss.str();
    }
    string CVMState::getString() {
        stringstream ss;
        ss << " ------------------------------------------- " << endl;
        ss << "|------------ Simulation State -------------|" << endl;
        ss << "|-------------------------------------------|" << endl;
        if (isChangeSelected()) {
        ss << "|                                           |" << endl;
        ss << "|       -----------------------------       |" << endl;
        ss << "|     /-------------------------------\\     |" << endl;
        ss << "|    |-------- Change Selected --------|    |" << endl;
        ss << "|     \\-------------------------------/     |" << endl;
        ss << "|       -----------------------------       |" << endl;
        ss << "|                                           |" << endl;
        } else {
        ss << "|                                           |" << endl;
        ss << "|                                           |" << endl;
        ss << "|                                           |" << endl;
        ss << "|            Change Not Selected            |" << endl;
        ss << "|                                           |" << endl;
        ss << "|                                           |" << endl;
        ss << "|                                           |" << endl;
        }
        ss << "|-------------------------------------------|" << endl;
        ss << "| Transaction Storage |   Master Storage    |" << endl;
        ss << "|---------------------|---------------------|" << endl;
        ss << "|                     |                     |" << endl;
        int currentCents = getCurrentCents();
        int totalCents = getTotalCents();
        stringstream currentCentsStream, totalCentsStream;
        currentCentsStream << "$" << (double)currentCents/100;
        totalCentsStream <<   "$" << (double)totalCents/100;
        string currentCentsString = currentCentsStream.str();
        string totalCentsString = totalCentsStream.str();
        ss << "| " << currentCentsString
           << getRightPadding(currentCentsString, 19);
        ss << " | " << totalCentsString
           << getRightPadding(totalCentsString, 19);
        ss << " |" << endl;
        // Pad

        ss << getStringLine("Quarters: ", currentQuarters, totalQuarters);
        ss << getStringLine("Dimes:    ", currentDimes, totalDimes);
        ss << getStringLine("Nickels:  ", currentNickels, totalNickels);
        ss << "|                     |                     |" << endl;
        ss << " ------------------------------------------- " << endl;
        return ss.str();
    }
    int* CVMState::makeChange(int changeCents, int quartersAvailable,
                              int dimesAvailable, int nickelsAvailable,
                              int* changeArray) {
        //int* changeArray;
        int quartersToOutput = 0, dimesToOutput = 0, nickelsToOutput = 0;

        while (changeCents >= 25 && quartersAvailable > 0) {
            changeCents -= 25;
            quartersAvailable--;
            quartersToOutput++;
        }
        while (changeCents >= 10 && dimesAvailable > 0) {
            changeCents -= 10;
            dimesAvailable--;
            dimesToOutput++;
        }
        while (changeCents >= 5 && nickelsAvailable > 0) {
            changeCents -= 5;
            nickelsAvailable--;
            nickelsToOutput++;
        }
        if (changeCents > 0) {
            changeArray = NULL;
        } else {
            //changeArray = new int[3];
            changeArray[0] = quartersToOutput;
            changeArray[1] = dimesToOutput;
            changeArray[2] = nickelsToOutput;
        }
        return changeArray;
    }


    int* CVMState::makeChangeFor(int changeCents, int* changeArray) {
        changeArray = makeChange(changeCents, currentQuarters,
                                 currentDimes, currentNickels, changeArray);
        return changeArray;
    }



    int* CVMState::changeToProvide(int* changeArray) {
        return makeChangeFor(centsToDispense(), changeArray);
    }



    bool CVMState::canProvideChange() {
        int* changeArray = new int[3];
        changeArray = changeToProvide(changeArray);
        bool output = changeArray != NULL;
        delete changeArray;
        return output;
    }


    void CVMState::removeChangeFromTransactionStorage(int* changeArray) {
        currentQuarters -= changeArray[0];
        currentDimes -= changeArray[1];
        currentNickels -= changeArray[2];
    }


    void CVMState::addChangeToTransactionStorage(int* changeArray) {
        currentQuarters += changeArray[0];
        currentDimes += changeArray[1];
        currentNickels += changeArray[2];
    }



    void CVMState::removeChangeFromMainStorage(int* changeArray) {
        totalQuarters -= changeArray[0];
        totalDimes -= changeArray[1];
        totalNickels -= changeArray[2];
    }



    void CVMState::addChangeToMainStorage(int* changeArray) {
        totalQuarters += changeArray[0];
        totalDimes += changeArray[1];
        totalNickels += changeArray[2];
    }



    void CVMState::moveChangeToTransactionStorage(int* changeArray) {
        removeChangeFromMainStorage(changeArray);
        addChangeToTransactionStorage(changeArray);
    }


    void CVMState::moveChangeToMainStorage(int* changeArray) {
        removeChangeFromTransactionStorage(changeArray);
        addChangeToMainStorage(changeArray);
    }


    int CVMState::numberOfCoffeesToDispense() {
        return getCurrentCents() / 100;
    }


    int CVMState::centsToDispense() {
        return getCurrentCents()%100;
    }




    void CVMState::changeStateForDispensedCoffee() {
        // Move all coffee money to main storage
        int numberOfCoffees = numberOfCoffeesToDispense();
        int* changeArray = new int[3];
        changeArray = makeChangeFor(numberOfCoffees*100, changeArray);
        if (changeArray != NULL) {
            moveChangeToMainStorage(changeArray);
        } else {
            int currentExcessCents = centsToDispense();
            // Move all current moneys to main storage
            moveCentsToMainStorage(getCurrentCents());
            // Try to get some back from main storage
            moveCentsToTransactionStorage(currentExcessCents);
        }
        delete changeArray;
        /*
        if (canProvideChange()) {
            moveCentsToMainStorage(numberOfCoffees*100);
        } else {
            moveCentsToMainStorage(getCurrentCents());
        }
        */
    }
    

    int* CVMState::changeStateForDispensedChange(int* changeArray) {
        changeArray = makeChangeFor(getCurrentCents()%100, changeArray);
        if (changeArray != NULL) {
            removeChangeFromTransactionStorage(changeArray);
        }
        setChangeSelected(false);
        return changeArray;
    }
}
