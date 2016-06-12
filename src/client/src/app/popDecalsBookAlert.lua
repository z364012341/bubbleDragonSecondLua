local alert = require(DECALS_EXHIBITION_ALERT_PATH):create();
--alert:setScaleY(bs.SmartScaleController:getInstance():getPlayAreaZoom());
cc.Director:getInstance():getRunningScene():addChild(alert);