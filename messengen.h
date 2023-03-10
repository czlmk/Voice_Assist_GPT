#ifndef MESSAGEN_H
#define MESSAGEN_H

#include <map>
#include <string>
#include <nlohmann/json.hpp>

class MessaGen {
public:
    MessaGen(std::string& model, std::string& prompt, std::string& suffix, int max_tokens, float temperature,
               float top_p, int n, bool stream, int logprobs, bool echo, std::string& stop, float frequency_penalty, float presence_penalty ,
               int best_of, const std::map<std::string&, int> logit_bias, std::string& user);
               
    //setter
    void setPrompt(std::string& prompt);
    void setSuffix(std::string& suffix);
    void setMaxTokens(int max_tokens);
    void setTemperature(int temperature);
    void setTopP(float top_p);
    void setFrequencyPenalty(float frequency_penalty);
    void setPresencePenalty(float presence_penalty);
    void setStop(std::string& stop);
    void setUser(std::string& user);

    //getters
    const std::string& getPrompt() const;
    const std::string& getSuffix() const;
    int getMaxTokens() const;
    int getTemperature() const;
    float getTopP() const;
    float getFrequencyPenalty() const;
    float getPresencePenalty() const;
    const std::string& getStop() const;
    const std::string& getUser() const;

    nlohmann::json toJSON() const;

private:
    std::string prompt_;
    std::string suffix_;
    int max_tokens_;
    int temperature_;
    float top_p_;
    float frequency_penalty_;
    float presence_penalty_;
    std::string stop_;
    std::string user_;
};

#endif 
