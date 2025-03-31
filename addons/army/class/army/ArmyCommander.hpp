GCLASS(ArmyCommander) = [
	["aggression",0.5],
	["reserveRate",0.1],
	["#create", {	
		params ["_module"];
	}],
	["FrontalAssult",{
		
		private _reserveManPower = manPower * reserveRate;
		private _frontLineManPower = 1 - _reserveManPower;
		private _attackingManPower = _frontLineManPower * aggression;
		private _defensingManPower = 1 - _attackingManPower;

		private _lotteryList = [];
		for "_i" from 0 to (count _subUnits - 1) do{
			_lotteryList pushBack _i;
		};
		for "_i" from 0 to _hoge do {
			private _lotteryNum = random (count _lotteryList);
			private _lotteried =  _lotteryList select _lotteryNum;
			//Some process
			

			_lotteryList deleteAt _lotteryNum;
		};
	}]
];
