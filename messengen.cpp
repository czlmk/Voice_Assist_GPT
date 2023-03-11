#include "messengen.h"

MessaGen::MessaGen(std::string& model, std::string& prompt, std::string& suffix, int max_tokens, float temperature,
                   float top_p, int n, bool stream, int logprobs, bool echo, std::string& stop, float presence_penalty, float frequency_penalty,
                   int best_of, const std::map<std::string, int> logit_bias, std::string& user)
    :prompt_(prompt), suffix_(suffix), max_tokens_(max_tokens), temperature_(temperature), top_p_(top_p),n_(n), stream_(stream), logprobs_(logprobs),
    echo_(echo), stop_(stop), presence_penalty_(presence_penalty), frequency_penalty_(frequency_penalty), logit_bias_(logit_bias), user_(user)
{
    // Initialize the class with the given arguments
}

// Setter methods
void MessaGen::setPrompt(std::string& prompt)
{
    prompt_ = prompt;
}

void MessaGen::setSuffix(std::string& suffix)
{
    suffix_ = suffix;
}

void MessaGen::setMaxTokens(int max_tokens)
{
    max_tokens_ = max_tokens;
}

void MessaGen::setTemperature(float temperature)
{
    temperature_ = temperature;
}

void MessaGen::setTopP(float top_p)
{
    top_p_ = top_p;
}
void MessaGen::setN(int n)
{
    n_ = n;
}
void MessaGen::setStream(bool stream)
{
    stream_ = stream;
}
void MessaGen::logprobs(int logprobs)
{
    logprobs_ = logprobs;
}
void MessaGen::setEcho(bool echo)
{
    echo_ = echo;
}

void MessaGen::setFrequencyPenalty(float frequency_penalty)
{
    frequency_penalty_ = frequency_penalty;
}

void MessaGen::setPresencePenalty(float presence_penalty)
{
    presence_penalty_ = presence_penalty;
}

void MessaGen::setBestOf(int best_of)
{
    best_of_ = best_of;
}

void MessaGen::setLogitBias(std::map<std::string, int> logit_bias)
{
    logit_bias_ = logit_bias;
}

void MessaGen::setStop(std::string stop)
{
    stop_ = stop;
}

void MessaGen::setUser(std::string& user)
{
    user_ = user;
}


// Getter methods
const std::string& MessaGen::getPrompt() const
{
    return prompt_;
}

const std::string& MessaGen::getSuffix() const
{
    return suffix_;
}

int MessaGen::getMaxTokens() const
{
    return max_tokens_;
}

float MessaGen::getTemperature() const
{
    return temperature_;
}

float MessaGen::getTopP() const
{
    return top_p_;
}
int MessaGen::getN() const
{
    return n_;
}

bool MessaGen::getStream() const
{
    return stream_;
}

int MessaGen::getLogprobs() const
{
    return logprobs_;
}

bool MessaGen::getEcho() const
{
    return echo_;
}

const std::string& MessaGen::getStop() const
{
    return stop_;
}
float MessaGen::getFrequencyPenalty() const
{
    return frequency_penalty_;
}

float MessaGen::getPresencePenalty() const
{
    return presence_penalty_;
}

int MessaGen::getBestOf() const
{
    return best_of_;
}
    
std::map<std::string, int> MessaGen::getLogitBias() const
{
    return logit_bias_;
}


const std::string& MessaGen::getUser() const
{
    return user_;
}

// Convert the object to a JSON representation
nlohmann::json MessaGen::toJSON() const
{
    nlohmann::json json_obj;
    json_obj["model"] = model_;
    json_obj["prompt"] = prompt_;
    json_obj["suffix"] = suffix_;
    json_obj["max_tokens"] = max_tokens_;
    json_obj["temperature"] = temperature_;
    json_obj["top_p"] = top_p_;
    json_obj["frequency_penalty"] = frequency_penalty_;
    json_obj["presence_penalty"] = presence_penalty_;
    json_obj["stop"] = stop_;
    json_obj["user"] = user_;

    return json_obj;
}
