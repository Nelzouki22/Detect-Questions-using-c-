#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// دالة للتحقق مما إذا كانت الجملة سؤالاً
bool isQuestion(const std::string& sentence) {
    // قائمة الكلمات التي تشير إلى الأسئلة
    std::vector<std::string> questionWords = { "what", "when", "where", "who", "whom", "which", "why", "how",
                                              "is", "are", "do", "does", "did", "can", "could", "would", "will",
                                              "shall", "should" };

    // تقسيم الجملة إلى كلمات
    std::string firstWord;
    size_t pos = sentence.find(' ');
    if (pos != std::string::npos) {
        firstWord = sentence.substr(0, pos);
    }
    else {
        firstWord = sentence;
    }

    // تحويل الكلمة الأولى إلى حروف صغيرة
    std::transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::tolower);

    // التحقق مما إذا كانت الكلمة الأولى من الكلمات التي تشير إلى الأسئلة
    if (std::find(questionWords.begin(), questionWords.end(), firstWord) != questionWords.end()) {
        return true;
    }

    // التحقق مما إذا كانت الجملة تنتهي بعلامة استفهام
    if (sentence.back() == '?') {
        return true;
    }

    return false;
}

int main() {
    // بعض الجمل لاختبار الكود
    std::vector<std::string> sentences = {
        "What is your name?",
        "This is a statement.",
        "Are you coming to the party?",
        "It's raining today."
    };

    for (const std::string& sentence : sentences) {
        if (isQuestion(sentence)) {
            std::cout << "'" << sentence << "' is a question." << std::endl;
        }
        else {
            std::cout << "'" << sentence << "' is not a question." << std::endl;
        }
    }

    return 0;
}
