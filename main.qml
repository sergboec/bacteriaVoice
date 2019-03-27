import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtMultimedia 5.8

Window {
    signal submitTextField(string text)

    id: mainWidnow
    visible: true
    width: 640
    height: 480
    title: qsTr("Bacteria Voice")

    SplitView{
        anchors.fill: parent
        orientation: Qt.Horizontal

        Rectangle{
            width: mainWidnow.width / 2
            color: "lightblue"

            Text {
                id: name
                anchors.centerIn: parent
                text: qsTr("el texto sobre bacterias")
            }
        }
        Rectangle{
            width: mainWidnow.width / 2
            color: "lightgreen"
            ColumnLayout{
                spacing: 2
                anchors.centerIn: parent

                TextArea{
                    id: input
                    width: parent.width/ 2
                    height: parent.height/ 2
                    text: ""

                }
                Button{
                    objectName: "submitButton"
                    id: submitButton
                    text: "submit your emotions"
                    onClicked: {
                        submitTextField(input.text)
                    }
                }
                Audio {
                    id: playMusic
                    source: "music.wav"
                }
            }
        }
    }

    // this function is our QML slot
    function setMusicTrack(musicPath){
        console.log("!set music path! = "+ musicPath)
        playMusic.source = musicPath
        playMusic.play()
    }
}
