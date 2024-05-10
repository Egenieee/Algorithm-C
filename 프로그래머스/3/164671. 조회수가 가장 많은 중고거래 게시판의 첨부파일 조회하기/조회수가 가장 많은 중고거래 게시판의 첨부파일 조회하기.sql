-- 조회수가 가장 높은 중고거래 게시물에 대한 첨부파일 경로 조회 
-- 첨부파일 경로는 FILE ID를 기준으로 내림차순 정렬
-- 기본적인 파일경로 /home/grep/src/이며, 게시글 ID를 기준으로  디렉토리가 구분되고
-- 파일 이름은 파일ID, 파일 이름, 파일 확장자로 구성되도록 출력

select CONCAT('/home/grep/src/', F.BOARD_ID, '/', F.FILE_ID, F.FILE_NAME, F.FILE_EXT) as FILE_PATH
from USED_GOODS_BOARD as B inner join USED_GOODS_FILE as F on B.BOARD_ID = F.BOARD_ID
where B.VIEWS = (select MAX(VIEWS) from USED_GOODS_BOARD)
order by F.FILE_ID DESC