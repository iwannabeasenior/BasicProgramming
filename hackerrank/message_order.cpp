#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public: 
    Message(const string& text): message(text) {
        rank_message++;
        rank=rank_message;
    };
    const string& get_text() {
        return message;
    }
    const int& get_rank(){
        return rank;
    }
    bool operator <(Message& );
private:
 string message;
 static int rank_message;
 int rank;
};


//--------------------------------------------------------------------
// overloading operator to sort by using std::sort function
bool Message:: operator <(Message&mg){
    if(rank<=mg.get_rank()) return true;
    else return false;
}
//--------------------------------------------------------------------



class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message mg(text);
        return mg;
    }
};
// initialize rank_message in Message class =0
int  Message::rank_message=0;

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
