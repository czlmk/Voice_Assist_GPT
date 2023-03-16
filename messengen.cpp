#include "messengen.h"

MessenGen::MessenGen()
    :model_("gpt-3.5-turbo"),prompt_(""), suffix_(""), max_tokens_(16), temperature_(1.0), top_p_(1.0),n_(1), stream_(false), logprobs_(0),
    echo_(false), stop_("."), presence_penalty_(0.0), frequency_penalty_(0.0),best_of_(1), logit_bias_({}), user_("")
{
    // Initialize the class with the given arguments
}

std::string MessenGen::toJSONs() const
{
    std::string json_str = "{";
    json_str += "\"model\":\"" + model_ + "\",";
    if(!prompt_.empty()) json_str += "\"prompt\":\"" + prompt_ + "\",";
    if(!suffix_.empty()) json_str += "\"suffix\":\"" + suffix_ + "\",";
    if(max_tokens_ != 16) json_str += "\"max_tokens\":" + std::to_string(max_tokens_) + ",";
    if(temperature_ != 1.0) json_str += "\"temperature\":" + std::to_string(temperature_) + ",";
    if(top_p_ != 1.0) json_str += "\"top_p\":" + std::to_string(top_p_) + ",";
    if(n_ != 1) json_str += "\"n\":" + std::to_string(n_) + ",";
    if(stream_) json_str += "\"stream\":true,";
    if(logprobs_) json_str += "\"logprobs\":true,";
    if(echo_) json_str += "\"echo\":true,";
    if(frequency_penalty_) json_str += "\"frequency_penalty\":" + std::to_string(frequency_penalty_) + ",";
    if(presence_penalty_) json_str += "\"presence_penalty\":" + std::to_string(presence_penalty_) + ",";
    if(!stop_.empty()) json_str += "\"stop\":\"" + stop_ + "\",";
    if(best_of_ != 1) json_str += "\"best_of\":" + std::to_string(best_of_) + ",";
    if (!logit_bias_.empty()) 
    {
        json_str += "\"logit_bias\":{";
        for (auto const& kv : logit_bias_) 
        {
            json_str += "\"" + kv.first + "\":" + std::to_string(kv.second) + ",";
        }
        json_str.pop_back(); // remove the last comma
        json_str += "},";
    }
    if(!user_.empty()) json_str += "\"user\":\"" + user_ + "\",";
    // Remove the last comma if there is one
    if(json_str.back() == ',') {
        json_str.pop_back();
    }
    json_str += "}";
    return json_str;
}
// Convert the object to a JSON representation
nlohmann::json MessenGen::toJSON() const
{
    nlohmann::json json_obj;
    json_obj["model"] = model_;
    if(!prompt_.empty()) json_obj["prompt"] = prompt_;
    if(!suffix_.empty()) json_obj["suffix"] = suffix_;
    if(max_tokens_ != 16) json_obj["max_tokens"] = max_tokens_;
    if(temperature_ != 1.0) json_obj["temperature"] = temperature_;
    if(top_p_ != 1.0) json_obj["top_p"] = top_p_;
    if(n_ != 1)json_obj["n"] = n_;
    if(stream_) json_obj["stream"] = stream_;
    if(logprobs_) json_obj["logprobs"] = logprobs_;
    if(echo_) json_obj["echo"] = echo_;
    if(frequency_penalty_) json_obj["frequency_penalty"] = frequency_penalty_;
    if(presence_penalty_) json_obj["presence_penalty"] = presence_penalty_;
    if(!stop_.empty()) json_obj["stop"] = stop_;
    if(best_of_ != 1) json_obj["best_of"] = best_of_;
    if(!logit_bias_.empty())json_obj["logit_bias"] = logit_bias_;
    if(!user_.empty()) json_obj["user"] = user_;

    return json_obj;
}

// Setter methods
MessenGen& MessenGen::setModel(std::string model)
{
    model_ = model; return *this;
}

MessenGen& MessenGen::setPrompt(std::string prompt)
{
    prompt_ = prompt; return *this;
}

MessenGen& MessenGen::setSuffix(std::string suffix)
{
    suffix_ = suffix; return *this;
}

MessenGen& MessenGen::setMaxTokens(int max_tokens)
{
    max_tokens_ = max_tokens; return *this;
}

MessenGen& MessenGen::setTemperature(float temperature)
{
    temperature_ = temperature; return *this;
}

MessenGen& MessenGen::setTopP(float top_p)
{
    top_p_ = top_p; return *this;
}

MessenGen& MessenGen::setN(int n)
{
    n_ = n; return *this;
}
MessenGen& MessenGen::setStream(bool stream)
{
    stream_ = stream; return *this;
}
MessenGen& MessenGen::logprobs(int logprobs)
{
    logprobs_ = logprobs; return *this;
}
MessenGen& MessenGen::setEcho(bool echo)
{
    echo_ = echo; return *this;
}

MessenGen& MessenGen::setFrequencyPenalty(float frequency_penalty)
{
    frequency_penalty_ = frequency_penalty; return *this;
}

MessenGen& MessenGen::setPresencePenalty(float presence_penalty)
{
    presence_penalty_ = presence_penalty; return *this;
}

MessenGen& MessenGen::setBestOf(int best_of)
{
    best_of_ = best_of; return *this;
}

MessenGen& MessenGen::setLogitBias(std::map<std::string, int> logit_bias)
{
    logit_bias_ = logit_bias; return *this;
}

MessenGen& MessenGen::setStop(std::string stop)
{
    stop_ = stop; return *this;
}

MessenGen& MessenGen::setUser(std::string& user)
{
    user_ = user; return *this;
}


// Getter methods
const std::string MessenGen::getModel() const
{
    return model_;
}
const std::string MessenGen::getPrompt() const
{
    return prompt_;
}

const std::string MessenGen::getSuffix() const
{
    return suffix_;
}

int MessenGen::getMaxTokens() const
{
    return max_tokens_;
}

float MessenGen::getTemperature() const
{
    return temperature_;
}

float MessenGen::getTopP() const
{
    return top_p_;
}
int MessenGen::getN() const
{
    return n_;
}

bool MessenGen::getStream() const
{
    return stream_;
}

int MessenGen::getLogprobs() const
{
    return logprobs_;
}

bool MessenGen::getEcho() const
{
    return echo_;
}

const std::string MessenGen::getStop() const
{
    return stop_;
}
float MessenGen::getFrequencyPenalty() const
{
    return frequency_penalty_;
}

float MessenGen::getPresencePenalty() const
{
    return presence_penalty_;
}

int MessenGen::getBestOf() const
{
    return best_of_;
}
    
std::map<std::string, int> MessenGen::getLogitBias() const
{
    return logit_bias_;
}


const std::string MessenGen::getUser() const
{
    return user_;
}


