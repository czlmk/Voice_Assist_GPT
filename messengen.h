#ifndef MESSAGEN_H
#define MESSAGEN_H

#include <map>
#include <string>
#include <nlohmann/json.hpp>

class MessaGen {
public:
    MessaGen(std::string& model, std::string& prompt, std::string& suffix, int max_tokens, float temperature,
               float top_p, int n, bool stream, int logprobs, bool echo, std::string& stop, float presence_penalty , float frequency_penalty,
               int best_of, std::map<std::string, int> logit_bias, std::string& user);
               
    //setter
    void setModel(std::string& model);
    void setPrompt(std::string& prompt);
    void setSuffix(std::string& suffix);
    void setMaxTokens(int max_tokens);
    void setTemperature(float temperature);
    void setTopP(float top_p);
    void setN(int n);
    void setStream(bool stream);
    void logprobs(int logprobs);
    void setEcho(bool echo);
    void setStop(std::string stop);
    void setPresencePenalty(float presence_penalty);
    void setFrequencyPenalty(float frequency_penalty);
    void setBestOf(int best_of);
    void setLogitBias(std::map<std::string, int> logit_bias);
    void setUser(std::string& user);

    //getters
    const std::string getModel() const;
    const std::string& getPrompt() const;
    const std::string& getSuffix() const;
    int getMaxTokens() const;
    float getTemperature() const;
    float getTopP() const;
    int getN() const;
    bool getStream() const;
    int getLogprobs() const;
    bool getEcho() const;
    const std::string& getStop() const;
    float getFrequencyPenalty() const;
    float getPresencePenalty() const;
    int getBestOf() const;
    std::map<std::string, int> getLogitBias() const;
    const std::string& getUser() const;

    nlohmann::json toJSON() const;

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
