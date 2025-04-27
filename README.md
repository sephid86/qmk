제가 사용하는 QMK 키보드 소스 파일들 입니다.
--
-- 이곳의 자료를 이용하여 발생하는 모든 책임은 사용자에게 있습니다. -- 
<br>
<br>

![20250426_190920](https://github.com/user-attachments/assets/946bd8a9-b66d-4618-bdf0-c01fac5de286)
<br>
<br>
cstc40
--
2024년 6월 이후 공급된 cstc40 은 pcb 가 변경되어 qmk 를 지원하지 않으며<br>
vial 을 지원하지만 주요 기능들이 막혀있고 레이어도 4개로 제한되어 있습니다.<br>
<br>
이곳의 소스파일을 이용하면 해당 모델에서 qmk 사용이 가능합니다.<br>
그리고 RGB 를 사용할수 없습니다.<br>
<br>
1. cstc40v2 디렉토리를 qmk 의 keyboards/kprepublic 아래에 복사해줍니다.<br>
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
<br>
cstc40 핀 아웃 출처 <br>
https://www.reddit.com/user/Accomplished_Pick819/<br>
https://www.reddit.com/r/olkb/comments/1hkfo6g/comment/m72ccp8/?context=3<br>
<br>
참고 - 확실하지는 않고 pcb 마다 다를지 모르나 <br>
구글 검색 결과 cstc40 의 EEPROM size 는 64kb 로 추정됩니다.<br>
<br>

<img src="https://github.com/user-attachments/assets/a7e9f4f1-db40-4354-9d6d-72f8d089b8fd">

gk61 pro
--
skyloong gk61 pro 스페이스바가 빨간색 스플릿 모델입니다. (사진첨부)<br>
qmk 공식에 소스파일이 없어서 구글검색으로 찾아낸 소스파일입니다.<br>
pro_ds 디렉토리를 qmk 의 keyboards/skyloong/gk61 디렉토리로 복사해서 사용하시면 됩니다.<br>
<br>
<br>

