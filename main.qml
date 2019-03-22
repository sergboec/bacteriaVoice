import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtMultimedia 5.8

Window {
    id: mainWidnow
    visible: true
    width: 640
    height: 480
    title: qsTr("Bacteria Voice")
//        visibility: "FullScreen"

    SplitView{
        anchors.fill: parent
        orientation: Qt.Horizontal

//        Keys.onEscapePressed: {
//            mainWidnow.visibility = "Windowed"
//            event.accept = true
//        }

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
                    text: "Hola!"

                }
                Button{
                    text: "submit your emotions"
                    onClicked: {
                        var text = input.text

                        var hapinessSet = new Set(  )
                        var conflictSet = new Set( )
                        var stressSet = new Set(  )
                        var lonelinessSet = new Set(  )
                        var psycicSet = new Set (  )
                        var pools = [
                                    {pool: hapinessSet,count:0,path:"path1.wav"},
                                    {pool: conflictSet,count:0,path:"path2.wav"},
                                    {pool: stressSet,count:0,path:"path3.wav"},
                                    {pool: lonelinessSet,count:0,path:"path4.wav"},
                                    {pool: psycicSet,count:0,path:"path5.wav"},
                                    ]
                        for(var word of text.split(" ")){
                            for(var poolObject of pools){
                                if(poolObject.pool.has(word)){
                                    poolObject.count++
                                }
                            }
                        }

                        function indexOfMaxCount(arr) {
                            var max = arr[0].count;
                            var maxIndex = 0;

                            for (var i = 1; i < arr.length; i++) {
                                if (arr[i].count > max) {
                                    maxIndex = i;
                                    max = arr[i];
                                }
                            }

                            return maxIndex;
                        }
                        var musicPath = pools[indexOfMaxCount(pools)].path
                        console.log(musicPath)
                        playMusic.source = musicPath
                        playMusic.play()
                    }
                }
                Audio {
                    id: playMusic
                    source: "music.wav"
                }
            }
        }
    }


}
