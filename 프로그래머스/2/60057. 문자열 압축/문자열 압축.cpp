#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>

using namespace std;

int compress(string& in, int ngram)
{
    int len = in.size();
    
    string last_str;
    int last_count = -1;
    
    string sb = "";
    string s_buffer;
    char c_buffer[1024];
    
    for (int idx = 0; idx < len; idx += ngram)
    {
        if (last_count == -1)
        {
            last_count = 1;
            last_str = in.substr(idx, ngram);
            continue;
        }
        
        string current_str = in.substr(idx, ngram);
        if (current_str == last_str)
        {
            last_count += 1;
        }
        else
        {
            if (last_count == 1)
            {
                snprintf(c_buffer, 1024, "%s", last_str.c_str());
            }
            else
            {
                snprintf(c_buffer, 1024, "%d%s", last_count, last_str.c_str());   
            }
            s_buffer = string(c_buffer);
            sb += s_buffer;
            
            last_str = current_str;
            last_count = 1;
        }
    }
    
    if (last_count == 1)
    {
        snprintf(c_buffer, 1024, "%s", last_str.c_str());
        s_buffer = string(c_buffer);
        sb += s_buffer;
    }
    else if (last_count > 1)
    {
        snprintf(c_buffer, 1024, "%d%s", last_count, last_str.c_str());   
        s_buffer = string(c_buffer);
        sb += s_buffer;
    }

    return sb.size();
}

int solution(string s)
{
    int len = s.size();
    int answer = len;
    
    for (int ngram_size = 1; ngram_size < len - 1; ++ngram_size)
    {
        int result = compress(s, ngram_size);
        if (result < answer)
        {
            answer = result;
        }
    }
    return answer;
}