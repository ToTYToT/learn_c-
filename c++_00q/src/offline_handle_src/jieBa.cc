#include "cppjieba/Jieba.hpp"
#include "jieBa.h"
namespace T520
{
const char* const DICT_PATH = "../dict/jieba.dict.utf8";
const char* const HMM_PATH = "../dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "../dict/user.dict.utf8";
const char* const IDF_PATH = "../dict/idf.utf8";
const char* const STOP_WORD_PATH = "../dict/stop_words.utf8";

int jieBa::jieBaVector(string s,vector<string> words) {
    cppjieba::Jieba jieba(DICT_PATH,
                          HMM_PATH,
                          USER_DICT_PATH,
                          IDF_PATH,
                          STOP_WORD_PATH);
    jieba.Cut(s, words, true);
    //vector<string>::iterator iter;
    //for(iter=words.begin();iter!=words.end();++iter)
    //cout<<*iter<<endl;
    return EXIT_SUCCESS;
}
}
//int main(void)
//{
//    jieBaVector("你是哪一个来的齐天大圣!");
//}
