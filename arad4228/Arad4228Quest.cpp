#include "pch.h"
#include "Arad4228Quest.h"

void Arad4228Quest::QueryNpcEx(std::vector<ST_QUEST_NPC_DATA>& vecNPC)
{
    ST_QUEST_NPC_DATA npc;
    npc.nNpcID = 154;	// NpcID는 구글 시트에서 확인하여 작성할 것
    npc.cPatch = 'A';
    npc.Color = ST_COLOR(0x99, 0x32, 0xCC);// 다크오치드

    npc.strTrack = TEXT("보안개발트랙");
    npc.strName = TEXT("장비전문가 정경재");
    npc.nAge = 24;
    npc.strMBTI = TEXT("ENFJ");
    npc.strMessage = TEXT("후우... 개발이 가장 최고입니다.. 개발로 오세요~~~");

    npc.strContents1 =
        TEXT("으음... 오늘도 출근을 해야하는데 뭐지 뭔가 이상한데..\n")
        TEXT("2023년??.. 어라 분명히 난 BoB를 졸업한지 좀 된거 같았는데...\n")
        TEXT("어라 생각해보니 나는 BoB에서 공통 부반장을 했었던 거 같은데...\n")
        TEXT("다시 2025년의 생활로 돌아가자. 또 다시 여기는 안돼!!!\n")
        ;

    npc.strContents2 =
        TEXT("나는 꼭 제품개발가야지. 다른 곳은 정말로 안돼..\n")
        TEXT("휴.. 더이상 센터의 음향장비는 만지지 않아도 되겠군..\n")
        TEXT("공통 부반장은 정말 지옥이였어..\n")
        ;
    
    npc.strContents3 =
        TEXT("아직까지는 버틸만 해 이제 얼마 남지 않았어..\n")
        TEXT("조금만 더 힘내면 수료할 수 있어!!!.\n")
        ;
    
    npc.strContents4 =
        TEXT("드디어 BoB에 수료하고 다시 내 본업으로 복귀할 수 있어!!\n")
        ;
    vecNPC.push_back(npc);

}

void Arad4228Quest::QueryQuestObject(std::vector<ST_QUEST_OBJECT>& vecQuestObject)
{
    {
        ST_QUEST_OBJECT stObject;
        stObject.nQuestObjectId = 2003;	                // 반드시 고유한 ID를 적을 것!!
        stObject.strName = TEXT("RSA의 개인키이다.");
        stObject.cPatch = TEXT('d');	                // 화면에 보이지도 않고 만져지지도 않게 하려면 0을 넣으면 됨
        vecQuestObject.push_back(stObject);
    }
    
    {
        ST_QUEST_OBJECT stObject;
        stObject.nQuestObjectId = 2005;	                // 반드시 고유한 ID를 적을 것!!
        stObject.strName = TEXT("RSA의 N값이다.");
        stObject.cPatch = TEXT('n');	                // 화면에 보이지도 않고 만져지지도 않게 하려면 0을 넣으면 됨
        vecQuestObject.push_back(stObject);
    }

    {
        ST_QUEST_OBJECT stObject;
        stObject.nQuestObjectId = 2023;	                // 반드시 고유한 ID를 적을 것!!
        stObject.strName = TEXT("꼬맹이 강태영");
        stObject.cPatch = TEXT('G');	                // 화면에 보이지도 않고 만져지지도 않게 하려면 0을 넣으면 됨
        vecQuestObject.push_back(stObject);
    }
}

void Arad4228Quest::QueryQuestItem(std::vector<ST_QUEST_ITEM_DATA>& vecQuestItem)
{
    {
        ST_QUEST_ITEM_DATA item;
        item.dwId = 3005;
        item.nHP = 0;
        item.nMP = 0;
        item.strName = TEXT("누군가 잃어버린 RSA로 암호화된 쪽지이다.");
        item.strDesc = TEXT("내용을 전혀 알아볼 수 없다.");
        vecQuestItem.push_back(item);
    }

    {
        ST_QUEST_ITEM_DATA item;
        item.dwId = 3013;
        item.nHP = 32768;
        item.nMP = 80;
        item.strName = TEXT("꼬맹이 강태영이 마시던 몬스터 음료이다. MP를 80을 올려준다.");
        item.strDesc = TEXT("이 음료를 마신다면 꼬맹이 강태영의 각성효과(?)를 누를 수 있다.");
        vecQuestItem.push_back(item);
    }

    {
        ST_QUEST_ITEM_DATA item;
        item.dwId = 3015;
        item.nHP = 0;
        item.nMP = 0;
        item.strName = TEXT("꼬맹이가 즐겨먹는 사탕이다.");
        item.strDesc = TEXT("누군가에게 주면 좋은 아이템을 줄지도 모른다.");
        vecQuestItem.push_back(item);
    }
}

void Arad4228Quest::QueryQuest(std::vector<ST_QUEST_DATA>& vecQuest)
{

    {
        ST_QUEST_DATA stQuest;
        stQuest.nNpcId = 154;
        stQuest.StartCondition = ST_FILTER(154, 0x0000, 0x0001);
        stQuest.vecMessages.push_back(TEXT("길에서 주웠는데 도통 뭐라고 써있는지 모르겠어."));
        stQuest.vecMessages.push_back(TEXT("혹시 해석할 수 있다면 해석해봐~"));
        stQuest.vecRewardItems.push_back(3005);
        stQuest.vecMessages.push_back(TEXT("[아이템 획득] '누군가 잃어버린 RSA 암호문'을 얻었다."));
        stQuest.ClearCondition = ST_FILTER(154, 0x0003);
        vecQuest.push_back(stQuest);
    }

	{
		ST_QUEST_DATA stQuest;
		stQuest.nNpcId = 2023;
		stQuest.StartCondition = ST_FILTER(154, 0x0001, 0x0003);
		stQuest.vecMessages.push_back(TEXT("Zzzzzz"));
		stQuest.vecMessages.push_back(TEXT("일어나!! (흔들흔들)"));
		stQuest.vecMessages.push_back(TEXT("Zzzzzzzz"));
		stQuest.vecMessages.push_back(TEXT("빨리 일어나!! (흔들흔들)"));
		stQuest.vecMessages.push_back(TEXT("Zzzzzzzzzz"));
		stQuest.vecMessages.push_back(TEXT("( 아직 성장기라 잠이 많은 듯 하다.. )"));
		stQuest.vecMessages.push_back(TEXT("그를 깨우기 위해 아이템이 필요할 듯 하다."));
        stQuest.vecMessages.push_back(TEXT("다시 정경재에게 돌아가보자."));
		stQuest.ClearCondition = ST_FILTER(154, 0x0007);
		vecQuest.push_back(stQuest);
	}

	{
		ST_QUEST_DATA stQuest;
		stQuest.nNpcId = 154;
		stQuest.StartCondition = ST_FILTER(154, 0x0003, 0x0007);
        stQuest.vecRewardItems.push_back(3015);
		stQuest.vecMessages.push_back(TEXT("[아이템 획득] '꼬맹이의 사탕'을 얻었다."));
		stQuest.ClearCondition = ST_FILTER(154, 0x000F);
		vecQuest.push_back(stQuest);
	}

	{
		ST_QUEST_DATA stQuest;
		stQuest.nNpcId = 2023;
		stQuest.StartCondition = ST_FILTER(154, 0x0007, 0x000F);
		stQuest.vecMessages.push_back(TEXT("Zzzzzzz"));
		stQuest.vecMessages.push_back(TEXT("(흔들흔들)"));
		stQuest.vecMessages.push_back(TEXT("꼬맹이의 입에 사탕을 넣어 줬다."));
		stQuest.vecMessages.push_back(TEXT("Zzzzzz... (벌떡) 흡.."));
        stQuest.vecMessages.push_back(TEXT("이제 수업시간인가요??"));
        stQuest.vecMessages.push_back(TEXT("이 음료수 먹으면 안졸려요."));
        stQuest.vecRewardItems.push_back(3013);
        stQuest.vecMessages.push_back(TEXT("[아이템 획득] '꼬맹이의 몬스터'를 얻었다."));
		stQuest.ClearCondition = ST_FILTER(154, 0x001F);
		vecQuest.push_back(stQuest);
	}

	
}
