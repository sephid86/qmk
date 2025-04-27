# 제가 사용하는 QMK 키보드 소스 파일들 입니다.
--이곳 자료를 이용하여 발생하는 모든 책임은 사용자에게 있습니다.--

cstc40
--
2024년11월 이후 공급된 cstc40 은 pcb 가 변경되어 qmk 를 지원하지 않으며<br>
vial 을 지원하지만 주요 기능들이 막혀있고 레이어도 4개로 제한되어 있습니다.<br>
<br>
이곳의 소스파일을 이용하면 해당 모델에서 qmk 사용이 가능합니다.<br>
그리고 RGB 를 사용할수 없습니다.<br>
<br>
1. cstc40v2 다운받거나 클론하여 qmk 의 keyboards/kprepublic 아래에 복사해줍니다.<br>
2. 아래 명령어로 컴파일 해줍니다.<br>
   qmk compile -kb kprepublic/cstc40v2/single_pcb -km sephid86<br>
3. 정상적으로 컴파일이 완료되었다면 키보드를 부트모드로 진입합니다.<br>
   키보드 ESC 키를 누른 상태에서 USB 케이블을 연결하거나<br>
   키보드 뒷면의 리셋 스위치를 눌러 부트모드로 진입합니다.<br>
4. 파일탐색기를 실행하여 USB 스토리지가 하나 추가된게 보인다면 정상적으로<br>
   부트모드에 진입한것입니다.<br>
5. 컴파일한 파일을 USB 스토리지에 복사해주면 자동으로 플래시가 즉시 적용됩니다. <br>
<br><br>
오버라이딩이나 탭댄스 , vial 활성화 기타 등등은 <br>
qmk 웹사이트에 문서가 잘되어 있으므로 참고 바랍니다.<br>

-- vial --<br>
첨부된 펌웨어 파일 플래시 하시면 됩니다.<br>
<br>
플래시 방법은 위 내용의 3번 부터 동일 합니다.<br>
<br>
- 직접 컴파일 할경우 -<br>
https://github.com/vial-kb/vial-qmk<br>
에서 클론 하고<br>
keyboards/kprepublic 디렉토리에 소스파일 복사한 뒤에<br>
vial-qmk 디렉토리로 이동하여 아래 명령어 입력 하면 됩니다.<br>
make kprepublic/cstc40v2/single_pcb:vial<br>

