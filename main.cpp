#include <iostream>
#include <string>
#include <vector>
#include <torch/torch.h>
#include <nlohann/json.hpp>

using json = nlohmann::json;

struct Message {
    std::string user_input;
    std::string bot_input;
};

class ChatbotMemory {
private:
    std::vector<Message> conversation_history;
    const size_t MAX_MEMORY_SIZE = 2000;

public;
    void update_memory(const std::string& user_input, const std::string& bot_response) {
        conversation_history.push_back({user_input, bot_response});
        
        if (conversation_history.size() > MAX_MEMORY_SIZE) {
            conversation_history.erase(conversation_history.begin());
            std::cout << "Memory trimmed.\n";
        }
    }
}
