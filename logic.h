#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QDebug>
#include <QRegularExpression>
#include <QUrl>
#include <QChar>

class Counter
{
    long counter;
public:
    Counter() {counter = 0L;}
    void increment(){counter++;}
    long get(){return counter;}
};

class LogicClass : public QObject
{
    Q_OBJECT


    QSet<QString> hapinnessSet = {"умиротворение", "заинтересованность", "доверие", "принятие", "радость познания", "радость", "экстаз", "счастье", "удовольствие", "восторг", "безмятежность", "восхищение", "возбуждение", "изумление", "любовь", "нежность", "забота", "очарованность", "воодушевление", "вдохновение", "умиротворения", "умиротворению", "умиротворение", "умиротворением", "умиротворении", "заинтересованности", "заинтересованности", "заинтересованность", "заинтересованностью", "заинтересованности", "доверия", "доверию", "доверие", "доверием", "доверии", "принятия", "принятию", "принятие", "принятием", "принятии", "радости познания", "радости познания", "радость познания", "радостью познания", "радости познания", "радости", "радости", "радость", "радостью", "радости", "экстаза", "экстазу", "экстаз", "экстазом", "экстазе", "счастья", "счастью", "счастье", "счастьем", "счастье", "удовольствия", "удовольствию", "удовольствие", "удовольствием", "удовольствии", "восторга", "восторгу", "восторг", "восторгом", "восторге", "безмятежности", "безмятежности", "безмятежность", "безмятежностью", "безмятежности", "восхищения", "восхищению", "восхищение", "восхищением", "восхищении", "возбуждения", "возбуждению", "возбуждение", "возбуждением", "возбуждении", "изумления", "изумлению", "изумление", "изумлением", "изумлении", "любви", "любви", "любовь", "любовью", "любви", "нежности", "нежности", "нежность", "нежностью", "нежности", "заботы", "заботе", "заботу", "заботой", "заботе", "очарованности", "очарованности", "очарованность", "очарованностью", "очарованности", "воодушевления", "воодушевлению", "воодушевление", "воодушевлением", "воодушевлении", "вдохновения", "вдохновению", "вдохновение", "вдохновением", "вдохновении"};
    QSet<QString> conflictSet = {"усталость", "отвращение", "агрессия", "гнев", "страх", "ужас", "скука", "неудовольствие", "досада", "злость", "настороженность", "обескураженность", "озабоченность", "замешательство", "возмущение", "оторопь", "презрение", "безразличие", "усталости", "усталости", "усталость", "усталостью", "усталости", "отвращения", "отвращению", "отвращение", "отвращением", "отвращении", "агрессии", "агрессии", "агрессию", "агрессией", "агрессии", "гнева", "гневу", "гнев", "гневом", "гневе", "страха", "страху", "страх", "страхом", "страхе", "ужаса", "ужасу", "ужас", "ужасом", "ужасе", "скуки", "скуке", "скуку", "скукой", "скуке", "неудовольствия", "неудовольствию", "неудовольствие", "неудовольствием", "неудовольствии", "досады", "досаде", "досаду", "досадой", "досаде", "злости", "злости", "злость", "злостью", "злости", "настороженности", "настороженности", "настороженность", "настороженностью", "настороженности", "обескураженности", "обескураженности", "обескураженность", "обескураженностью", "обескураженности", "озабоченности", "озабоченности", "озабоченность", "озабоченностью", "озабоченности", "замешательства", "замешательству", "замешательство", "замешательством", "замешательстве", "возмущения", "возмущению", "возмущение", "возмущением", "возмущении", "оторопи", "оторопи", "оторопь", "оторопью", "оторопи", "презрения", "презрению", "презрение", "презрением", "презрении", "безразличия", "безразличию", "безразличие", "безразличием", "безразличии"};
    QSet<QString> stressSet = {"стресс", "напряженность", "тревога, тревожность", "паника", "истощение", "обеспокоенность", "перенапряжение", "сонливость", "безысходность", "вялость", "тяжесть", "раздражение", "неловкость", "стресса", "стрессу", "стресс", "стрессом", "стрессе", "напряженности", "напряженности", "напряженность", "напряженностью", "напряженности", "тревоги, тревожности", "тревоге, тревожности", "тревогу, тревожность", "тревогой, тревожностью", "тревоге, тревожности", "паники", "панике", "панику", "паникой", "панике", "истощения", "истощению", "истощение", "истощением", "истощении", "обеспокоенности", "обеспокоенности", "обеспокоенность", "обеспокоенностью", "обеспокоенности", "перенапряжения", "перенапряжению", "перенапряжение", "перенапряжением", "перенапряжении", "сонливости", "сонливости", "сонливость", "сонливостью", "сонливости", "безысходности", "безысходности", "безысходность", "безысходностью", "безысходности", "вялости", "вялости", "вялость", "вялостью", "вялости", "тяжести", "тяжести", "тяжесть", "тяжестью", "тяжести", "раздражения", "раздражению", "раздражение", "раздражением", "раздражении", "неловкости", "неловкости", "неловкость", "неловкостью", "неловкости"};
    QSet<QString> lonelinessSet = {"одиночество", "отключенность", "потерянность", "печаль", "горе", "отчуждение", "апатия", "отчаяние", "одиночества", "одиночеству", "одиночество", "одиночеством", "одиночестве", "отключенности", "отключенности", "отключенность", "отключенностью", "отключенности", "потерянности", "потерянности", "потерянность", "потерянностью", "потерянности", "печали", "печали", "печаль", "печалью", "печали", "горя", "горю", "горе", "горем", "горе", "отчуждения", "отчуждению", "отчуждение", "отчуждением", "отчуждении", "апатии", "апатии", "апатию", "апатией", "апатии", "отчаяния", "отчаянию", "отчаяние", "отчаянием", "отчаянии"};
    QSet<QString> phycicSet = {"депрессия", "паранойя", "психоз", "шизофрения", "меланхолия", "истерика", "депрессии", "депрессии", "депрессию", "депрессией", "депрессии", "паранойи", "паранойе", "паранойю", "паранойей", "паранойе", "психоза", "психозу", "психоз", "психозом", "психозе", "шизофрении", "шизофрении", "шизофрению", "шизофренией", "шизофрении", "меланхолии", "меланхолии", "меланхолию", "меланхолией", "меланхолии", "истерики", "истерике", "истерику", "истерикой", "истерике"};
    QMap<QString,QString> dnaMapping = {
        {"0","ATA"},
        {"1","TCT"},
        {"2","GCG"},
        {"3","GTG"},
        {"4","AGA"},
        {"5","CGC"},
        {"6","ATT"},
        {"7","ACC"},
        {"8","AGG"},
        {"9","CAA"},

        {"а","ACT"},
        {"б","CAT"},
        {"в","TCA"},
        {"г","TAC"},
        {"д","CTA"},
        {"е","GCT"},
        {"ё","GTC"},
        {"ж","CGT"},
        {"з","CTG"},
        {"и","TGC"},
        {"й","TCG"},
        {"к","ATC"},
        {"л","ACA"},
        {"м","CTC"},
        {"н","TGT"},
        {"о","GAG"},
        {"п","TAT"},
        {"р","CAC"},
        {"с","TGA"},
        {"т","TAG"},
        {"у","GAT"},
        {"ф","GTA"},
        {"х","ATG"},
        {"ц","AGT"},
        {"ч","GAC"},
        {"ш","GCA"},
        {"щ","AGC"},
        {"ь","ACG"},
        {"ы","TTG"},
        {"ъ","ACG"},
        {"э","AAA"},
        {"ю","TAA"},
        {"я","TAA"},
    };



public slots:
    void cppSlot(const QString &v) {


        //guessing emotion from text
        Counter hapinnessCounter;
        Counter conflictCounter;
        Counter stressCounter;
        Counter lonelinessCounter;
        Counter psycicCounter;

        std::vector<std::pair<std::pair<std::string,Counter*>,QSet<QString>*>> sets = {
                                                                      {{"/home/sergey.boytsov/Documents/projects/cpp/build-bacteriaVoice-Desktop_Qt_5_13_0_GCC_64bit-Debug/overture.mp3",&hapinnessCounter},&hapinnessSet},
                                                                      {{"conflict.wav",&conflictCounter},&conflictSet},
                                                                      {{"stress.wav",&stressCounter},&stressSet},
                                                                      {{"loneliness.wav",&lonelinessCounter},&lonelinessSet},
                                                                      {{"psy.wav",&psycicCounter},&phycicSet}};

        QString input = v.toLower();
        QStringList words = input.split(QRegularExpression(QString("\\s|\\n|\\r\\n")));

        foreach (QString word, words) {
            foreach (auto set, sets) {
                QSet<QString>* dt = set.second;
                if(dt->contains(word)){
                    set.first.second->increment();
                }
            }
        }

        foreach (auto set, sets) {
            qDebug() << QString::fromStdString(set.first.first) << "  " << set.first.second->get();
        }

        if(sets[0].first.second->get() == 0 &&
                sets[1].first.second->get() == 0 &&
                sets[2].first.second->get() == 0 &&
                sets[3].first.second->get() == 0 &&
                sets[4].first.second->get() == 0 ){
            //todo throw "cannot parse"
        }

        size_t maxIndex = 0;
        long maxValue = sets[0].first.second->get();
        for(size_t i=1; i<sets.size(); i++){
            if(sets[i].first.second->get() > maxValue){
                maxValue = sets[i].first.second->get();
                maxIndex = i;
            }
        }

        QString filePathToPlay = QString::fromStdString(sets[maxIndex].first.first);

        emit setMusicTrack(QUrl::fromLocalFile(filePathToPlay));

        //translating text to dna
        updateDNAText(v);

    }
    void updateDNAText(const QString &v) {
        QString input = v.toLower();

        QString result = "ATG";
        for(auto i=0;i<input.size();i++){
            auto val = QString(input.at(i));
            qDebug() << "mapping dna" << val;
            result += dnaMapping.find(val) != dnaMapping.end() ? dnaMapping.find(val).value() : "";
        }
        result += "TGA";
        emit setDNAText(result);
    }
signals:
  void setMusicTrack(QVariant text);
  void setDNAText(QVariant text);
};

#endif // LOGIC_H