#ifndef MESSENGEN_H
#define MESSENGEN_H

#include <map>
#include <string>
#include <nlohmann/json.hpp>

class MessenGen {
public:
/*
    MessenGen(std::string model = "gpt-3.5-turbo", std::string prompt = "", std::string suffix = "", int max_tokens = 16, float temperature = 1.0,
               float top_p = 1.0, int n = 1, bool stream = false, int logprobs = 0, bool echo = false, std::string stop = ".", float presence_penalty = 0.0,
               float frequency_penalty = 0.0, int best_of = 1, std::map<std::string, int> logit_bias = {}, std::string user = "");
               */
    MessenGen();

    nlohmann::json toJSON() const;           
    //setter
    MessenGen& setModel(std::string model);
    MessenGen& setPrompt(std::string prompt);
    MessenGen& setSuffix(std::string suffix);
    MessenGen& setMaxTokens(int max_tokens);
    MessenGen& setTemperature(float temperature);
    MessenGen& setTopP(float top_p);
    MessenGen& setN(int n);
    MessenGen& setStream(bool stream);
    MessenGen& logprobs(int logprobs);
    MessenGen& setEcho(bool echo);
    MessenGen& setStop(std::string stop);
    MessenGen& setPresencePenalty(float presence_penalty);
    MessenGen& setFrequencyPenalty(float frequency_penalty);
    MessenGen& setBestOf(int best_of);
    MessenGen& setLogitBias(std::map<std::string, int> logit_bias);
    MessenGen& setUser(std::string& user);

    //getters
    const std::string getModel() const;
    const std::string getPrompt() const;
    const std::string getSuffix() const;
    int getMaxTokens() const;
    float getTemperature() const;
    float getTopP() const;
    int getN() const;
    bool getStream() const;
    int getLogprobs() const;
    bool getEcho() const;
    const std::string getStop() const;
    float getFrequencyPenalty() const;
    float getPresencePenalty() const;
    int getBestOf() const;
    std::map<std::string, int> getLogitBias() const;
    const std::string getUser() const;

    

private:
    std::string model_;
    std::string prompt_;
    std::string suffix_;
    int max_tokens_;
    int temperature_;
    float top_p_;
    int n_;
    bool stream_;
    int logprobs_;
    bool echo_;
    std::string stop_;
    float presence_penalty_;
    float frequency_penalty_;
    int best_of_;
    std::map<std::string, int> logit_bias_;
    std::string user_;
};

#endif 
