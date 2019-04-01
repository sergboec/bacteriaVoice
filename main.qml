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
    FontLoader { id:museoSansCyrl; source: "qrc:/font/MuseoSansCyrl.otf" }

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
                font.family: museoSansCyrl.name
                font.pixelSize: mainWidnow.height * 1.15 * 1.15 / 55
                text: "Resilent\nEc(h)osystem"
                color: "white"
            }

            Text {
                id: name
                anchors.topMargin: parent.width / 17
                anchors.left: title.left
                anchors.top: title.bottom
                width: parent.width * 0.6
                wrapMode: Text.WordWrap
                font.family: museoSansCyrl.name
                font.pixelSize: mainWidnow.height  / 55
                horizontalAlignment: Text.AlignJustify
                color: "white"
                text: qsTr("Сейчас Вы находитесь внутри руинированного пространства бывшего советского бассейна. В действующей лютеранской церкви.  На Невском проспекте. В Санкт-Петербурге. В этом скрытом пространстве Вы вступаете в контакт и участвуете в создании художественного техно-биологического микробиома, объединяющего через исцеляющие звуки бактерии, человека и архитектуру. Растущий микробиом реагирует на Ваши тревоги, страхи, любые эмоции и мысли, точно так же как на них реагируют и микроорганизмы, населяющие Ваше тело. Вы можете записать сюда любые Ваши тревоги, переживания, страхи, навязчивые мысли, которые беспокоят Вас, и разделить их с этим микробиомом. Ваш текст будет переведен в код ДНК (научный язык жизни), после чего в виде вибраций попадет на поверхность чашки Петри. Вибрации, проходя сквозь микробиом и влияя на его развитие и рост, будут трансформированы в исцеляющие звуки, заполняющие пространство, Ваше тело и микробиом в чашке Петри. Разделив свое бремя с другими, мы можем продолжать жить и меняться. Делиться по-настоящему полно и глубоко можно не только с человеком, но и другими созданиями, в том числе и теми, которые кажутся нам неодушевленными или которых мы не замечаем.")
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
                anchors.leftMargin: parent.width / 6
                anchors.topMargin: parent.height / 8

                id: input
                width: parent.width/ 1.5
                height: parent.height/ 2.5
                textFormat: Text.AutoText
                wrapMode: Text.WordWrap
                placeholderText: "оставьте ваши мысли здесь"
                clip: false
                font.pixelSize: mainWidnow.height  / 55


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
                font.pixelSize: mainWidnow.height  / 55

                onClicked: submitTextField(input.text)
            }

            TextArea{
                id: dnaOutput
                anchors.top: input.bottom
                anchors.left: input.left

                anchors.topMargin: parent.height / 10

                width: parent.width/ 1.5
                height: parent.height/ 4
                textFormat: Text.AutoText
                wrapMode: Text.WrapAnywhere
                font.pixelSize: mainWidnow.height  / 55

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
