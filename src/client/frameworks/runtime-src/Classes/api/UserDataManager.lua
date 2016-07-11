
--------------------------------
-- @module UserDataManager
-- @parent_module bs

--------------------------------
-- 
-- @function [parent=#UserDataManager] buyNewbieGift 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] savePuzzleStageData 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] cutPropsNumbleWithKey 
-- @param self
-- @param #string key
-- @param #int numble
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] setGameMusicEnable 
-- @param self
-- @param #bool flag
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getStageStartNumbleWithLevel 
-- @param self
-- @param #int level
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getLastGameCharactorIndex 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] isCompletedGame 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] isGameMusicEnable 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] saveStrengthLastTime 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] isUnlockWithStageNumble 
-- @param self
-- @param #int stage_numble
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] updateStageTotalStartScore 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] readDataFile 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getDecalsData 
-- @param self
-- @param #string decals_type
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] insertPuzzleStageData 
-- @param self
-- @param #string key
-- @param #int consumingTime
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getPuzzleStageBestScoreWithKey 
-- @param self
-- @param #string key
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] canBuyNewbieGift 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getStagePassCount 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] saveUserData 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getStrengthLastTime 
-- @param self
-- @return long#long ret (return value: long)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] setDecalsUserData 
-- @param self
-- @param #array_table data
-- @param #string decals_type
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getStageTotalStartScore 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] setPropsNumbleWithKey 
-- @param self
-- @param #string key
-- @param #int numble
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getStartNumbleWithLevel 
-- @param self
-- @param #int level
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] setPresentCell 
-- @param self
-- @param #int cell_numble
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] readDecalsData 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] addPropsNumbleWithKey 
-- @param self
-- @param #string key
-- @param #int numble
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getPropsNumbleWithKey 
-- @param self
-- @param #string key
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] setSoundEffectEnable 
-- @param self
-- @param #bool flag
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] readPuzzleStageBestScore 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] updateStageData 
-- @param self
-- @param #int level
-- @param #int start_numble
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getPresentCell 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getGameCharactorUnlockNumble 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] isSoundEffectEnable 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] addUnlockStageNumble 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] setLastGameCharactorIndex 
-- @param self
-- @param #int index
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getPuzzleAddTimePropKey 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getDecalsTreasureKey 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getDecalsCharactorKey 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getInstance 
-- @param self
-- @return UserDataManager#UserDataManager ret (return value: bs.UserDataManager)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getPuzzleSearchPropKey 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] getPuzzleBigEyesPropKey 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#UserDataManager] UserDataManager 
-- @param self
-- @return UserDataManager#UserDataManager self (return value: bs.UserDataManager)
        
return nil
