#include "pch.h"
#include "Arad4228Quest.h"

void Arad4228Quest::QueryNpcEx(std::vector<ST_QUEST_NPC_DATA>& vecNPC)
{
    ST_QUEST_NPC_DATA npc;
    npc.nNpcID = 154;	// NpcID�� ���� ��Ʈ���� Ȯ���Ͽ� �ۼ��� ��
    npc.cPatch = 'A';
    npc.Color = ST_COLOR(0x99, 0x32, 0xCC);// ��ũ��ġ��

    npc.strTrack = TEXT("���Ȱ���Ʈ��");
    npc.strName = TEXT("��������� ������");
    npc.nAge = 24;
    npc.strMBTI = TEXT("ENFJ");
    npc.strMessage = TEXT("�Ŀ�... ������ ���� �ְ��Դϴ�.. ���߷� ������~~~");

    npc.strContents1 =
        TEXT("����... ���õ� ����� �ؾ��ϴµ� ���� ���� �̻��ѵ�..\n")
        TEXT("2023��??.. ��� �и��� �� BoB�� �������� �� �Ȱ� ���Ҵµ�...\n")
        TEXT("��� �����غ��� ���� BoB���� ���� �ι����� �߾��� �� ������...\n")
        TEXT("�ٽ� 2025���� ��Ȱ�� ���ư���. �� �ٽ� ����� �ȵ�!!!\n")
        ;

    npc.strContents2 =
        TEXT("���� �� ��ǰ���߰�����. �ٸ� ���� ������ �ȵ�..\n")
        TEXT("��.. ���̻� ������ �������� ������ �ʾƵ� �ǰڱ�..\n")
        TEXT("���� �ι����� ���� �����̿���..\n")
        ;
    
    npc.strContents3 =
        TEXT("���������� ��ƿ�� �� ���� �� ���� �ʾҾ�..\n")
        TEXT("���ݸ� �� ������ ������ �� �־�!!!.\n")
        ;
    
    npc.strContents4 =
        TEXT("���� BoB�� �����ϰ� �ٽ� �� �������� ������ �� �־�!!\n")
        ;
    vecNPC.push_back(npc);

}

void Arad4228Quest::QueryQuestObject(std::vector<ST_QUEST_OBJECT>& vecQuestObject)
{
    {
        ST_QUEST_OBJECT stObject;
        stObject.nQuestObjectId = 2003;	                // �ݵ�� ������ ID�� ���� ��!!
        stObject.strName = TEXT("RSA�� ����Ű�̴�.");
        stObject.cPatch = TEXT('d');	                // ȭ�鿡 �������� �ʰ� ���������� �ʰ� �Ϸ��� 0�� ������ ��
        vecQuestObject.push_back(stObject);
    }
    
    {
        ST_QUEST_OBJECT stObject;
        stObject.nQuestObjectId = 2005;	                // �ݵ�� ������ ID�� ���� ��!!
        stObject.strName = TEXT("RSA�� N���̴�.");
        stObject.cPatch = TEXT('n');	                // ȭ�鿡 �������� �ʰ� ���������� �ʰ� �Ϸ��� 0�� ������ ��
        vecQuestObject.push_back(stObject);
    }

    {
        ST_QUEST_OBJECT stObject;
        stObject.nQuestObjectId = 2023;	                // �ݵ�� ������ ID�� ���� ��!!
        stObject.strName = TEXT("������ ���¿�");
        stObject.cPatch = TEXT('G');	                // ȭ�鿡 �������� �ʰ� ���������� �ʰ� �Ϸ��� 0�� ������ ��
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
        item.strName = TEXT("������ �Ҿ���� RSA�� ��ȣȭ�� �����̴�.");
        item.strDesc = TEXT("������ ���� �˾ƺ� �� ����.");
        vecQuestItem.push_back(item);
    }

    {
        ST_QUEST_ITEM_DATA item;
        item.dwId = 3013;
        item.nHP = 32768;
        item.nMP = 80;
        item.strName = TEXT("������ ���¿��� ���ô� ���� �����̴�. MP�� 80�� �÷��ش�.");
        item.strDesc = TEXT("�� ���Ḧ ���Ŵٸ� ������ ���¿��� ����ȿ��(?)�� ���� �� �ִ�.");
        vecQuestItem.push_back(item);
    }

    {
        ST_QUEST_ITEM_DATA item;
        item.dwId = 3015;
        item.nHP = 0;
        item.nMP = 0;
        item.strName = TEXT("�����̰� ��ܸԴ� �����̴�.");
        item.strDesc = TEXT("���������� �ָ� ���� �������� ������ �𸥴�.");
        vecQuestItem.push_back(item);
    }
}

void Arad4228Quest::QueryQuest(std::vector<ST_QUEST_DATA>& vecQuest)
{

    {
        ST_QUEST_DATA stQuest;
        stQuest.nNpcId = 154;
        stQuest.StartCondition = ST_FILTER(154, 0x0000, 0x0001);
        stQuest.vecMessages.push_back(TEXT("�濡�� �ֿ��µ� ���� ����� ���ִ��� �𸣰ھ�."));
        stQuest.vecMessages.push_back(TEXT("Ȥ�� �ؼ��� �� �ִٸ� �ؼ��غ�~"));
        stQuest.vecRewardItems.push_back(3005);
        stQuest.vecMessages.push_back(TEXT("[������ ȹ��] '������ �Ҿ���� RSA ��ȣ��'�� �����."));
        stQuest.ClearCondition = ST_FILTER(154, 0x0003);
        vecQuest.push_back(stQuest);
    }

	{
		ST_QUEST_DATA stQuest;
		stQuest.nNpcId = 2023;
		stQuest.StartCondition = ST_FILTER(154, 0x0001, 0x0003);
		stQuest.vecMessages.push_back(TEXT("Zzzzzz"));
		stQuest.vecMessages.push_back(TEXT("�Ͼ!! (������)"));
		stQuest.vecMessages.push_back(TEXT("Zzzzzzzz"));
		stQuest.vecMessages.push_back(TEXT("���� �Ͼ!! (������)"));
		stQuest.vecMessages.push_back(TEXT("Zzzzzzzzzz"));
		stQuest.vecMessages.push_back(TEXT("( ���� ������ ���� ���� �� �ϴ�.. )"));
		stQuest.vecMessages.push_back(TEXT("�׸� ����� ���� �������� �ʿ��� �� �ϴ�."));
        stQuest.vecMessages.push_back(TEXT("�ٽ� �����翡�� ���ư�����."));
		stQuest.ClearCondition = ST_FILTER(154, 0x0007);
		vecQuest.push_back(stQuest);
	}

	{
		ST_QUEST_DATA stQuest;
		stQuest.nNpcId = 154;
		stQuest.StartCondition = ST_FILTER(154, 0x0003, 0x0007);
        stQuest.vecRewardItems.push_back(3015);
		stQuest.vecMessages.push_back(TEXT("[������ ȹ��] '�������� ����'�� �����."));
		stQuest.ClearCondition = ST_FILTER(154, 0x000F);
		vecQuest.push_back(stQuest);
	}

	{
		ST_QUEST_DATA stQuest;
		stQuest.nNpcId = 2023;
		stQuest.StartCondition = ST_FILTER(154, 0x0007, 0x000F);
		stQuest.vecMessages.push_back(TEXT("Zzzzzzz"));
		stQuest.vecMessages.push_back(TEXT("(������)"));
		stQuest.vecMessages.push_back(TEXT("�������� �Կ� ������ �־� ���."));
		stQuest.vecMessages.push_back(TEXT("Zzzzzz... (����) ��.."));
        stQuest.vecMessages.push_back(TEXT("���� �����ð��ΰ���??"));
        stQuest.vecMessages.push_back(TEXT("�� ����� ������ ��������."));
        stQuest.vecRewardItems.push_back(3013);
        stQuest.vecMessages.push_back(TEXT("[������ ȹ��] '�������� ����'�� �����."));
		stQuest.ClearCondition = ST_FILTER(154, 0x001F);
		vecQuest.push_back(stQuest);
	}

	
}
