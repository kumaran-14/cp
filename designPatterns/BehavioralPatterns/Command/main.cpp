/**
 * Command pattern decouples sender and receiver by encapsulating a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undo-able operations.
 * It can also be thought as an object oriented equivalent of call back method.
 * Call Back: It is a function that is registered to be called at later point of time based on user actions.
 * Note: Now the receiver object is not bound to the remote, but rather bound to the command.
 * The command itself is encapsulated. We can pass around commands to objects which run them.
 */
#include <iostream>

/**
 * Abstract Objects which represent real world electronics
 */
class IReceiver {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class Bulb : public IReceiver {
public:
    void turnOn() override {
        std::cout<<"The Bulb is switched on now"<<std::endl;
    }
    void turnOff() override {
        std::cout<<"The Bulb is switched off now"<<std::endl;
    }
};

class SoundBox : public IReceiver {
public:
    void turnOn() override {
        std::cout<<"The speaker is switched on now"<<std::endl;
    }
    void turnOff() override {
        std::cout<<"The speaker is switched off now"<<std::endl;
    }
};

/**
 * Abstract object to represent any type of command.
 */
class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};
//
class TurnOnCommand : public ICommand {
private:
    IReceiver* gadget_;
public:
    TurnOnCommand(IReceiver* gadget):
    gadget_{gadget}{}

    void execute() override {
        this->gadget_->turnOn();
    }
    void undo() override {
        this->gadget_->turnOff();
    }
    void redo() override {
        this->undo();
        this->execute();
    }
};

class TurnOffCommand : public ICommand {
private:
    IReceiver* gadget_;
public:
    TurnOffCommand(IReceiver* gadget):
    gadget_(gadget) {}

    void execute() override {
        this->gadget_->turnOff();
    }
    void undo() override {
        this->gadget_->turnOn();
    }
    void redo() override {
        this->undo();
        this->execute();
    }
};

/**
 * Abstract
 */
class IInvoker {

public:
    virtual void onClickTurnOn() = 0;
    virtual void onClickTurnOff() = 0;
    virtual void perform(ICommand* command) = 0;
};
//
class Remote : public IInvoker{
private:
    ICommand* turnOnCommand_;
    ICommand* turnOffCommand_;
public:
    Remote(ICommand* turnOnCommand, ICommand* turnOffCommand):
    turnOnCommand_(turnOnCommand),
    turnOffCommand_(turnOffCommand) {}

    void onClickTurnOn() override {
        this->turnOnCommand_->execute();
    }

    void onClickTurnOff() override {
        this->turnOffCommand_->execute();
    }

    void perform(ICommand* command) override {
        command->execute();
    }
};

int main() {
    IReceiver* neonBulb = new Bulb();
    ICommand* bulbOnCommand = new TurnOnCommand(neonBulb);
    ICommand* bulbOffCommand = new TurnOffCommand(neonBulb);

    IInvoker* bulbRemote = new Remote(bulbOnCommand, bulbOffCommand);
    bulbRemote->onClickTurnOn();
    bulbRemote->onClickTurnOff();

    IReceiver* speaker = new SoundBox();

    ICommand* speakerOnCommand = new TurnOnCommand(speaker);
    ICommand* speakerOffCommand = new TurnOffCommand(speaker);

    IInvoker* speakerRemote = new Remote(speakerOnCommand, speakerOffCommand);

    speakerRemote->onClickTurnOn();
    speakerRemote->onClickTurnOff();

    bool userClickedButtonOn = false;
    if(userClickedButtonOn) {
        speakerRemote->perform(speakerOnCommand);
    }
    return 0;
}



