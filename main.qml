import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtMultimedia 5.8

ApplicationWindow {
    signal submitTextField(string text)
    signal textDNAChanged(string text)

    id: mainWidnow
    visible: true
    width: 640
    height: 480
    title: qsTr("Resilent Ec(h)osystem")

    Rectangle{
        anchors.fill: parent

        Rectangle{
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: mainWidnow.width / 2

            color: "black"

            Text{
                id:title
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: parent.width / 10
                anchors.topMargin: parent.width / 10
                width: parent.width / 2
                font.family: "Helvetica"
                font.pointSize: 16
                text: "Resilent\nEc(h)osystem"
                color: "white"
            }

            Text {
                id: name
                anchors.centerIn: parent
                width: parent.width * 0.6
                wrapMode: Text.WordWrap
                font.family: "Helvetica"
                font.pointSize: 12
                color: "white"
                text: qsTr("Это новый технологический микробиом, связь между бактериями, человеком и архитектурой, которая наполняет пространство упругими звуками. Он отвечает на ваши проблемы, проблемы и мысли, как это делают микроорганизмы, живущие в вашем теле.
Когда вы записываете ситуацию, память, беспокойство или любую мысль, которую вы хотели бы освободить, она переводится в формат ДНК как простой акт общения на языке основных уровней жизни. Согласно вашему тексту, звук появится и заполнит катакомбы, и благодаря вибрационному звуку бремя вашей мысли может быть освобождено.
Только трудные времена приносят стойкость и выносливость.")
            }            
        }

        Rectangle{
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: mainWidnow.width / 2
            color: "black"

            TextArea{
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 4
                anchors.topMargin: parent.height / 6

                id: input
                width: parent.width/ 2
                height: parent.height/ 4
                textFormat: Text.AutoText
                wrapMode: Text.WordWrap
                placeholderText: "оставьте ваши мысли здесь"
                clip: false


                background: Rectangle {
                    border.color: "transparent"
                    color: "lightgray"
                }

                onTextChanged: textDNAChanged(text)
                onFocusChanged: if(focus) playMusic.stop()
            }
            RoundButton{
                anchors.left: input.right
                anchors.top: input.bottom
                anchors.leftMargin: -parent.width / 10
                anchors.topMargin: -parent.height / 10
                width: parent.width / 6
                height: parent.width / 6
                radius: width / 2
                objectName: "submitButton"
                id: submitButton
                text: "перевести"

                onClicked: submitTextField(input.text)
            }

            TextArea{
                id: dnaOutput
                anchors.top: input.bottom
                anchors.left: input.left

                anchors.topMargin: parent.height / 10

                width: parent.width/ 2
                height: parent.height/ 4
                textFormat: Text.AutoText
                wrapMode: Text.WrapAnywhere

                placeholderText: "тут появится dna ваших мыслей"

                background: Rectangle {
                    border.color: "transparent"
                    color: "lightgray"
                }
            }

            Audio {
                id: playMusic
            }
        }
    }

    // this function is our QML slot
    function setMusicTrack(musicPath){
        console.log("!set music path! = "+ musicPath)
        playMusic.source = musicPath
        playMusic.play()
    }
    function setOutputDNAText(text){
        console.log("set text to smthing")
        dnaOutput.text = text
    }
}
