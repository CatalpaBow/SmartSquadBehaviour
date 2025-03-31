GCLASS(DebugDisplay) = [
	/* Variables */
	["armyList",nil],
    ["unitTreeCtl",nil],
	["unitInfoCtl",nil],
	/* Constructer */ 
	["#create", {	
		params["_armyList"];
		_self set ["armyList",_armyList];
	}],
	["Open",{
        private _armyList = _self get "armyList";
        
        //CreateDisplay
        private _dis = findDisplay 313 createDisplay "SSBDisplayTest";
        private _unitTreeCtl = (_dis displayCtrl 1100) controlsGroupCtrl 1105;
        private _unitInfoCtl = (_dis displayCtrl 1200) controlsGroupCtrl 1201;
        _self set ["unitTreeCtl",_unitTreeCtl];
        _self set ["unitInfoCtl",_unitInfoCtl];

        //Set tree elements
        {   
            _x params["_army"];
            private _side = _army get "side";
            private _subUnits = _army get "unit" get "subUnits";
            _unitTreeCtl tvAdd[[],_side];
            [_unitTreeCtl,[_forEachIndex],_subUnits]call FUNC(recursion);
        }forEach(_self get "armyList");

        //Add an event handler to update the UnitInfo view when the tree selection changes
        _unitTreeCtl setVariable["treeSelChangedHdlr",_self];
        _unitTreeCtl ctrlAddEventHandler ["TreeSelChanged",{
	        params ["_control", "_selectionPath"];
            _control getVariable "treeSelChangedHdlr" call ["HandleTreeSelChanged",[_control,_selectionPath]];
        }];
	}],
	["HandleTreeSelChanged",{
        params ["_control", "_selectionPath"];

        private _sideIndex = _selectionPath select 0;
        private _side =  _self get "armyList" select _sideIndex;
        private _unitParent = _side get "unit";
        private _isNil = isNil "_unitParent";
        _msg = format["selectionPath:%1 ",_selectionPath];
        LOG(_msg);
        private _unitInstancePath = [_unitParent];

        {
            _msg = format["pathPart:%1,brothersCount:%2",_x,( count (_unitParent get "subUnits"))];
            LOG(_msg);
            private _pathUnit = _unitParent get "subUnits" select _x;
            _unitInstancePath pushBack (_pathUnit);
            _unitParent = _pathUnit;
        }forEach(_selectionPath);

        private _unit = _unitInstancePath select (count _unitInstancePath - 2);


        private _unitInfoCtl = _self get "unitInfoCtl";
        lnbClear _unitInfoCtl;
        _unitInfoList = (_unit get "subUnits") apply{
            private _name = _x get "unitName";
            private _mission = _x get "mission" get "type";
            private _deploymentArea = "kari";
            private _subUnitCount = str (_x call ["SubUnitCount"]);
            [_name,_mission,_deploymentArea,_subUnitCount];
        };
        { _unitInfoCtl lnbAddRow  _x;}forEach(_unitInfoList);

	}]

];