CREATE TABLE IF NOT EXISTS START_PARAMS(
	TASK_CODE int, 
	TASK VARCHAR(128), 
	STEP_CODE int, 
	STEP VARCHAR(128), 
	PROCESS_NO int default 1, 
	CHANNEL_FIELD VARCHAR(128), 
	LIB_NAME VARCHAR(128), 
	FUNC_NAME VARCHAR(128), 
	VALID_TAG CHAR(1) default '0');

CREATE TABLE IF NOT EXISTS START_PARAMS_CHANNEL(
	TASK_CODE int, 
	STEP_CODE int, 
	CHANNEL_NO int, 
	START_ID int, 
	END_ID int, 
	REMARK VARCHAR(128));

insert into START_PARAMS(TASK_CODE,TASK,STEP_CODE,STEP,PROCESS_NO,CHANNEL_FIELD,LIB_NAME,FUNC_NAME)
	values (1, 'MyTest', 1, 'MyTest1', 1, '', 'libMyTest1', 'MyTest1');
insert into START_PARAMS(TASK_CODE,TASK,STEP_CODE,STEP,PROCESS_NO,CHANNEL_FIELD,LIB_NAME,FUNC_NAME)
	values (1, 'MyTest', 2, 'MyTest2', 1, '', 'libMyTest2', 'MyTest2');
insert into START_PARAMS(TASK_CODE,TASK,STEP_CODE,STEP,PROCESS_NO,CHANNEL_FIELD,LIB_NAME,FUNC_NAME)
	values (2, 'MyCheck', 1, 'MyCheck', 1, '', 'libMyCheck', 'MyCheck');
insert into START_PARAMS(TASK_CODE,TASK,STEP_CODE,STEP,PROCESS_NO,CHANNEL_FIELD,LIB_NAME,FUNC_NAME)
	values (3, 'MyKitty', 1, 'MyKitty', 1, '', '/home/chenhuidong/MyProject/MyGit/MyCpp/MyFramework/test/libMySharedLibraryProvider', 'hellokitty');