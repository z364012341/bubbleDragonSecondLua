//*******************************************************************************
//������   : CXXX
//����     : <����Ŀ����,�޸�,����xml>
//-------------------------------------------------------------------------------
//��ע     : <����xml�ļ�>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _XML_TOOL_H_
#define _XML_TOOL_H_
#include <string>
namespace bubble_second {
    class StageDataModule;
    class XMLTool
    {
    public:
        XMLTool();
        ~XMLTool();
    public:
        //��ȡ�ؿ�������Ϣ
        StageDataModule* decodeStageXMLWithStageNumble(int stageNumble);
        int convertStringToInt(const std::string& str);

    };
}
#endif //_XML_TOOL_H_