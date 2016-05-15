cc.exports.GlobalFunction = {
	createGameSpriteWithPath = function (path)
		return cc.Sprite:create(path);
		--return cc.Sprite:createWithSpriteFrameName(path);
	end,
	setGameSpriteTextureWithPath = function (path, sprite)
		sprite:setTexture(path);
		--local frame = cc.SpriteFrameCache:getInstance():getSpriteFrameByName(path);
        --sprite:setSpriteFrame(frame);
	end,
	getPuzzlePiecePositionWithDirection = function (direction)
		return puzzle.PUZZLE_COMPONENT_DIRECTION_TO_DATA[direction][PUZZLE_COMPONENT_POSITION];
	end,
	getPuzzlePiecePositionWithRotation = function (direction, insideOrOutside)
		--assert(direction and insideOrOutside);
	    if insideOrOutside == PUZZLE_STENCIL_COMPONENT_OUTSIDE then
	        return puzzle.PUZZLE_COMPONENT_DIRECTION_TO_DATA[direction][PUZZLE_COMPONENT_ROTATION]+180;
	    else
	        return puzzle.PUZZLE_COMPONENT_DIRECTION_TO_DATA[direction][PUZZLE_COMPONENT_ROTATION];
	    end
	end,
	getVisibleCenterPosition = function ()
		local size = cc.Director:getInstance():getVisibleSize();
		return	cc.p(size.width*0.5, size.height*0.5);
	end
}
