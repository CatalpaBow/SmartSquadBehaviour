class SSBDisplayTest{
	idd = 1234;

	class ControlsBackground{
		/*
		class TreeBackGround : RscText
		{
			idc = -1;
			x = GUI_GRID_CENTER_X;
			y = GUI_GRID_CENTER_Y + 2 * GUI_GRID_CENTER_H;
			w = 10 * GUI_GRID_CENTER_W;
			h = 23 * GUI_GRID_CENTER_H;
			colorBackground[] = {0,1,0,1};
		};
		*/
		class Background : RscText
		{
			idc = -1;
			x = GUI_GRID_CENTER_X;
			y = GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 25 * GUI_GRID_CENTER_H;
			colorBackground[] = {0,0,0,0.8};
		};
	};
	class Controls{
		
		class UnitInfoRight:RscControlsGroupNoScrollbars{
			idc = 1200;
			x = GUI_GRID_CENTER_X + 10 * GUI_GRID_CENTER_W;
			y = GUI_GRID_CENTER_Y + 2 * GUI_GRID_CENTER_H;
			w = 30 * GUI_GRID_CENTER_W;
			h = 24 * GUI_GRID_CENTER_H;
			class Controls{
				class Header:RscListNBox{
					idc = 114515;
					x = 0;
					y = 0;
					w = 28 * GUI_GRID_CENTER_W;
					h = 1 * GUI_GRID_CENTER_H;
					disableOverflow = 1;
					columns[] = {0,0.3,0.6,0.8};
					colorSelect[] = {1,1,1,1};
					colorSelect2[] = {1,1,1,1};
					colorSelectBackground[] = {0,0,0,0};
					colorSelectBackground2[] = {0,0,0,0};
						class Items{
							class Name
							{
								text = "部隊名";
								value = 1;
								data = "value";
							};
							class Mission
							{
								text = "任務";
								value = 1;
								data = "value";
							};
							class DeploymentArea
							{
								text = "展開区域";
								value = -1;
							};
							class Manpower
							{
								text = "兵数";
								value = -1;
							};
						};
				};
				class Info:RscListNBox{
					idc = 1201;
					x = 0;
					y = 1 * GUI_GRID_CENTER_H;
					w = 28 * GUI_GRID_CENTER_W;
					h = 22 * GUI_GRID_CENTER_H;
					disableOverflow = 1;
					columns[] = {0,0.3,0.6,0.8};
					
					class Items{
						class Name
						{
							text = "歩兵分隊1-1";
							value = 1;
							data = "value";
						};
						class Mission
						{
							text = "防衛";
							value = 1;
							data = "value";
						};
						class DeploymentArea
						{
							text = "エリア1-1";
							value = -1;
						};
						class Manpower
						{
							text = "8人";
							value = -1;
						};
					};
					class ScrollBar{
						arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
						arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
						border = "#(argb,8,8,3)color(1,1,1,1)";
						color[] = {1,1,1,0.6};
						colorActive[] = {1,1,1,1};
						colorDisabled[] = {1,1,1,0.3};
						thumb = "#(argb,8,8,3)color(1,1,1,1)";
					};
				};
			};

		};
		class Header : RscControlsGroupNoScrollbars{
			idc = 1000;
			x = GUI_GRID_CENTER_X;
			y = GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 2 * GUI_GRID_CENTER_H;
			class Controls{
				class Title : RscText{
					x = 0;
					y = 0;
					w = 10 * GUI_GRID_CENTER_W;
					h = 2 * GUI_GRID_CENTER_H;
					text = "  画面(仮)";
					sizeEX  = 2 * GUI_GRID_CENTER_H;
				};
				class Sitrep : RscText{
					x = 10 * GUI_GRID_CENTER_W;
					y = 0;
					w = 10 * GUI_GRID_CENTER_W;
					h = 2 * GUI_GRID_CENTER_H;
					text = "SITREP";
					sizeEX  = 1.5 * GUI_GRID_CENTER_H;
				};

			};
		};
		
		class UnitTreeSidebar :RscControlsGroupNoScrollbars{
			idc = 1100;
			x = GUI_GRID_CENTER_X + 0 * GUI_GRID_CENTER_W;
			y = GUI_GRID_CENTER_Y + 2 * GUI_GRID_CENTER_H;
			w = 10 * GUI_GRID_CENTER_W;
			h = 20 * GUI_GRID_CENTER_H;
			class Controls{
				class Trees:RscTree{
					idc = 1105;
					x = 0;
					y = 0;
					w = 10 * GUI_GRID_CENTER_W;
					h = 38 * GUI_GRID_CENTER_H;
					defaultItem[] = {"BLU_F","Infantry"};
				};

			};
		};
		
		/*
		class UnitSize:RscControlsGroupNoScrollbars{
			#define CTR_WIDTH_TEMP 11 * GUI_GRID_CENTER_W
			idd = -1
			x = GUI_GRID_CENTER_X + 0 * GUI_GRID_CENTER_W;
			y = GUI_GRID_CENTER_Y + 0 * GUI_GRID_CENTER_H;
			w = CTR_WIDTH_TEMP;
			h = 1 * GUI_GRID_CENTER_H;
			class Controls{
				class Battalion:RscButton{
					idc = 1001;
					x = 0 * CTR_WIDTH_TEMP /3;
					y = 0;
					w = CTR_WIDTH_TEMP /3;
					h = 1 * GUI_GRID_CENTER_H;
					text = "Bn.";
				};
				class Coampnay:RscButton{
					idc = 1002;
					x = 1 * CTR_WIDTH_TEMP /3;
					y = 0;
					w = CTR_WIDTH_TEMP /3;
					h = 1 * GUI_GRID_CENTER_H;
					text = "Co.";
				};
				class Platoon:RscButton{
					idc = 1003;
					x = 2 * CTR_WIDTH_TEMP /3;
					y = 0;
					w = CTR_WIDTH_TEMP /3;
					h = 1 * GUI_GRID_CENTER_H;
					text = "Plt.";
				};
				#undef CTR_WIDTH_TEMP
			};
		};
		*/
	};


};
class SSBMapView : RscMapControl{
		idc = 1500;
		x = GUI_GRID_CENTER_X + 10 * GUI_GRID_CENTER_W;
		y = GUI_GRID_CENTER_Y + 2 * GUI_GRID_CENTER_H;
		w = 30 * GUI_GRID_CENTER_W;
		h = 23 * GUI_GRID_CENTER_H;
};