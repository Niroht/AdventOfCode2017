#include <iostream>;
#include <string>;
#include <sstream>;
#include <vector>;
#include <iterator>;

#include "InverseCaptcha.h";
#include "SpreadsheetAnalyser.h";
#include "PassphraseValidator.h";

using namespace std;


void main() {
	void SolveDayOne();
	void SolveDayTwo();
	void SolveDayFour();

	SolveDayOne();
	SolveDayTwo();
	SolveDayFour();

	string sentinel;
	cin >> sentinel;
}

void SolveDayOne() 
{
	InverseCaptcha inverseCaptcha;
	const string dayOneInput = "5672987533353956199629683941564528646262567117433461547747793928322958646779832484689174151918261551689221756165598898428736782194511627829355718493723961323272136452517987471351381881946883528248611611258656199812998632682668749683588515362946994415852337196718476219162124978836537348924591957188827929753417884942133844664636969742547717228255739959316351852731598292529837885992781815131876183578461135791315287135243541659853734343376618419952776165544829717676988897684141328138348382882699672957866146524759879236555935723655326743713542931693477824289283542468639522271643257212833248165391957686226311246517978319253977276663825479144321155712866946255992634876158822855382331452649953283788863248192338245943966269197421474555779135168637263279579842885347152287275679811576594376535226167894981226866222987522415785244875882556414956724976341627123557214837873872723618395529735349273241686548287549763993653379539445435319698825465289817663294436458194867278623978745981799283789237555242728291337538498616929817268211698649236646127899982839523784837752863458819965485149812959121884771849954723259365778151788719941888128618552455879369919511319735525621198185634342538848462461833332917986297445388515717463168515123732455576143447454835849565757773325367469763383757677938748319968971312267871619951657267913817242485559771582167295794259441256284168356292785568858527184122231262465193612127961685513913835274823892596923786613299747347259254823531262185328274367529265868856512185135329652635938373266759964119863494798222245536758792389789818646655287856173534479551364115976811459677123592747375296313667253413698823655218254168196162883437389718167743871216373164865426458794239496224858971694877159591215772938396827435289734165853975267521291574436567193473814247981877735223376964125359992555885137816647382139596646856417424617847981855532914872251686719394341764324395254556782277426326331441981737557262581762412544849689472281645835957667217384334435391572985228286537574388834835693416821419655967456137395465649249256572866516984318344482684936625486311718525523265165";

	cout << "Day One" << endl;
	cout << inverseCaptcha.CalculateInverseCaptcha(dayOneInput) << endl;
	cout << inverseCaptcha.CalculateInverseCaptchaPartTwo(dayOneInput) << endl;
}

void SolveDayTwo()
{
	SpreadsheetAnalyser spreadsheetAnalyser;
	const string dayTwoInput = "5806	6444	1281	38	267	1835	223	4912	5995	230	4395	2986	6048	4719	216	1201\n		74  127 226 84  174 280 94  159 198 305 124 106 205 99  177 294\n		1332    52  54  655 56  170 843 707 1273    1163    89  23  43  1300    1383    1229\n		5653    236 1944    3807    5356    246 222 1999    4872    206 5265    5397    5220    5538    286 917\n		3512    3132    2826    3664    2814    549 3408    3384    142 120 160 114 1395    2074    1816    2357\n		100 2000    112 103 2122    113 92  522 1650    929 1281    2286    2259    1068    1089    651\n		646 490 297 60  424 234 48  491 245 523 229 189 174 627 441 598\n		2321    555 2413    2378    157 27  194 2512    117 140 2287    277 2635    1374    1496    1698\n		101 1177    104 89  542 2033    1724    1197    474 1041    1803    770 87  1869    1183    553\n		1393    92  105 1395    1000    85  391 1360    1529    1367    1063    688 642 102 999 638\n		4627    223 188 5529    2406    4980    2384    2024    4610    279 249 2331    4660    4350    3264    242\n		769 779 502 75  1105    53  55  931 1056    1195    65  292 1234    1164    678 1032\n		2554    75  4406    484 2285    226 5666    245 4972    3739    5185    1543    230 236 3621    5387\n		826 4028    4274    163 5303    4610    145 5779    157 4994    5053    186 5060    3082    2186    4882\n		588 345 67  286 743 54  802 776 29  44  107 63  303 372 41  810\n		128 2088    3422    111 3312    740 3024    1946    920 131 112 477 3386    2392    1108    2741";
	stringstream dayTwoStream(dayTwoInput);

	vector<string> dayTwoRows;
	int rowCount = 0;
	while (dayTwoStream.good())
	{
		string singleLine;
		getline(dayTwoStream, singleLine, '\n');

		dayTwoRows.push_back(singleLine);
		rowCount++;
	}

	vector<vector<int>> dayTwoData;
	for (int i = 0; i < dayTwoRows.size(); i++)
	{
	    istringstream rowStringStream(dayTwoRows[i]);
		vector<string> rowString((istream_iterator<string>(rowStringStream)), istream_iterator<string>());

		vector<int> rowInts;

		for (int j = 0; j < rowString.size(); j++)
		{
			rowInts.push_back(atoi(rowString[j].c_str()));
		}
		dayTwoData.push_back(rowInts);
	}

	cout << "Day Two" << endl;
	cout << spreadsheetAnalyser.CalculateChecksum(dayTwoData) << endl;
	cout << spreadsheetAnalyser.SumEvenlyDivisibleValues(dayTwoData) << endl;
}

void SolveDayFour()
{
	PassphraseValidator passPhraseValidator;
	const string dayFourInput = "nyot babgr babgr kqtu kqtu kzshonp ylyk psqk\n"
"iix ewj rojvbkk phrij iix zuajnk tadv givslju ewj bda\n"
"isjur jppvano vctnpjp ngwzdq pxqfrk mnxxes zqwgnd giqh\n"
"ojufqke gpd olzirc jfao cjfh rcivvw pqqpudp\n"
"ilgomox extiffg ylbd nqxhk lsi isl nrho yom\n"
"feauv scstmie qgbod enpltx jrhlxet qps lejrtxh\n"
"wlrxtdo tlwdxor ezg ztp uze xtmw neuga aojrixu zpt\n"
"wchrl pzibt nvcae wceb\n"
"rdwytj kxuyet bqnzlv nyntjan dyrpsn zhi kbxlj ivo\n"
"dab mwiz bapjpz jbzppa\n"
"hbcudl tsfvtc zlqgpuk xoxbuh whmo atsxt pzkivuo wsa gjoevr hbcudl\n"
"gxhqamx dradmqo gxhqamx gxhqamx\n"
"yvwykx uhto ten wkvxyy wdbw\n"
"kzc ndzatgb rlxrk hfgorm qwgdky ndzatgb rhvyene qaa wxibe qwmku nmxkjqo\n"
"qwx ubca dxudny oxagv wqrv lhzsl qmsgv dxs awbquc akelgma\n"
"rrdlfpk ohoszz qiznasf awchv qnvse\n"
"ggsyj czcrdn oolj sibjzp ibzjps asp\n"
"vbcs ypgzae xcvpsr ptvb leoxqlq zmpt fhawu yfi tvbp\n"
"ejkr qlmag nsz jwpurli nhsml asksnug mes\n"
"kkgkjml kklmgjk kjgpx iquytbj eccceb mfv iuyqjbt ovv\n"
"uoklkco zzey sdfhiyv ytdeg\n"
"azr mjv raz arz rdfb\n"
"pir dafgsah dafgsah kndjbml estcz yjeoijp kkcws ebq puwno\n"
"iqymwc tac vlqc bmnkz xustm leqi\n"
"gwdjed cfha axz xjuq\n"
"abfjsg pahat qlj zan qsfn iozfys jnvu bis jakggq\n"
"afwuejn zrbu zurb hrn lwvjb jnwixla aufejnw\n"
"vkqn cuzf humhriz webnf uzfc zfuc\n"
"eznxd kgbfy jqyc net vzfege tprzyc\n"
"mqnapzn vrgw ilzp vgw\n"
"aie zkkih fhpwu bbn fhpwu wvxxgmd\n"
"ksoasrn yll mvdjxdo wydymx dmodvjx drnjlm tcjpjhj xzakb wrsbuwl vaygdwf rsasonk\n"
"qahbh tfhkl apdqqpm tfhkl nsox\n"
"xkelwve mvdmesj xrto tgku gkb bpe\n"
"nni nyylpu cyusxe zydeyok yokzdye xiscesy\n"
"itwsfr eqwrx igqkvif whklwdb\n"
"lpa hwci suwqfln xis sfht lzek ajecd\n"
"svpf eulute eya gvmsd app claria tjtk zjt agdyemi bixewo\n"
"gmzglxi zlgouy bejg kte xlf giquj mjeq ivjkw ktbhaga hoffyrt\n"
"wwjy dtf ftd agei yde xhbfo fyridy\n"
"gexcy hetkz ufflrfi frifluf plb kqre etxo elg henqy fspm\n"
"khaemn buec ichau wxctsxg\n"
"cgmv ujyvcuu jta yux ccx skrafkn cmyc yidqhv ltb ycnajry zitq\n"
"ybsahqn pio veeze vdztjz iedou pio sue ijbz gvqncl vpa ijbz\n"
"hkfi xzrsyke hikf mxolx xlxmo ungfc tst xjzd\n"
"tpx ioprco qixlv ipocro\n"
"oahmwrv homvraw vws ntmbdvx\n"
"fxlg wnuz ogt bxgtul vmfh nwuz glfx tgxdq bxfv kajuh\n"
"vrhqn nrqvh tgogb vya ragbro ulrz uava kexoi yav vkfe\n"
"bxxy tyxgxd oabsud bauosd jlch bdmrqq wqhjwb ayblb hclj\n"
"sfzsgsc sfzsgsc jbrvh sfzsgsc bdhy\n"
"wixleal vhnqbfw qwfnhbv woco oowc\n"
"exkkwz wekxzk krxbua nshxqgh\n"
"gkn blxgui nkg gnk\n"
"otsa isqn otsa isqn\n"
"ude xedl ude xedl amkktp\n"
"teroe yuvbd inf mpytuvz xiq xqi ovqetn\n"
"zyq ybeifwx fvoqp vhoduy bcq wbxl\n"
"zymiid vafcqv vjbmekf lgxkma bjti qfavcv iqp fnbu lakmgx\n"
"rkaqvd vylkh jfdxh imxxg bbrt imxxg rkaqvd\n"
"yajg qnhhs bzmb eyk hijcg tkij iwr jvwp dipzd jvwp\n"
"btzhw zttheyo ravsbz bmbba majoe ykrs tbxqf tai cgsvpu srbavz\n"
"vsyczfs ymg vsyczfs wxlwaqb oouio owek wxlwaqb azvbqiq\n"
"ghrapd ghrapd wisq wisq\n"
"znmleu aztnkbs wxc gycxd vqenhh geqyo rpjg\n"
"kxbom gzz zzg zgz\n"
"dfsesc okwb dfsesc okwb\n"
"egpwqbe djlk xpkxa hoo eepbqwg\n"
"nxdfror yfhkhn zgea fkspva rjgg bnmq ddsf rjgg gkinm\n"
"vdrxfom wbdwu dhkt xtvzc zjobo aqvgrt\n"
"svddsgz mhcrbcp wmpd mhcrbcp klim ddlnxv wrdftrc ddow wrdftrc\n"
"obxr wscs new brxo wen epns cvjvxts ilnc\n"
"rwezl vmbut kgblt xfg vnhlebq nzqdzxm ynh wokrezy zub nzzqxdm\n"
"vephajp bzupele mltzglh sbgn vephajp lhve mltzglh\n"
"slajp kyaf vlnvy srfietn ayfk inaufex fanuexi\n"
"vazwg kjg qanzso ptuu vvlwq uupt kohhql jkg\n"
"xmmmpky rbqimi slvxsf tlcwm pbf pks iucx rbmiqi\n"
"irkup jvu tkeioz avdu suxamf\n"
"tmgih ldca jswka dblzzt rap rgqyy gyrqsk nnnn pok\n"
"pdbjhrl gsvxbqr nqfkhtc ngn okbgzd pdbjhrl oostjtm okbgzd\n"
"mzqfdat dujh aeplzqh acbguic vlzdt amyszu amyszu jqecky bhl hjqnimq xoy\n"
"dszafr bqampg epozj sfrlpe dszafr wfurku sotjpg wagtnxy\n"
"jbmo jbmo plbfkvw bkc jbmo\n"
"ehelldu vrid unnf vrid xqiu tbibjyi bmbpsmq tpqyefx xqiu\n"
"rpgm zzbj cjgfdyb bdjfgcy rzqecd miyvfbu aqlkagf hsuxwgl\n"
"gvywzp phvnd ypwypbm yfelxx egbr lcfyz hecdhkj xxfley\n"
"tsmebin tbsnmie mkijj ijjmk\n"
"cghxrqs vzxle wrfghv skighgt zviteab plcrgv\n"
"ezdirp rxkw horcek qcgny inx nikb tigzp\n"
"eidk sactjci sre vkapava owvf eyds eyds\n"
"vvjdm uye tjixj azklizl pnb\n"
"tcrimv xye twii xye twii tad\n"
"mtxcg lwjxdj zjudqu ekoujd ysf ajtfta dkj lwjxdj\n"
"aowhmvv kkic kjize fnohl ukx remfmii usbp\n"
"wkossu limxmhp xnoeocb wkossu lnrlqf kjozfg xeulstx sjncsw ekaimuv xnoeocb sxjegcg\n"
"lsfe zpewzlc yhjyiay lou ukhi lpwezzc slef zvtidgg kdeseq enka tfvgudr\n"
"ovfsa vuv tbtorv tbtorv gmxn opspw lli mfzvkv zlyhr oznalr\n"
"kugrpw sduq rdc ciaxwir ylnzwec kugrpw sduq\n"
"obevuau thu jpyfvof rpawwo obevuau gsvoutr quiaei\n"
"xpgua pbxa pxgau kdan\n"
"ohyzqk abxgg xozgai nib axozig bni fucgykm jpkswt\n"
"jrgu dmozts jrug ufpho\n"
"qojzue uzeojq txuhj eqjzou\n"
"wcvj qwlravl niyxf oiaptlk wlxnnzj jgdzap jgdzap lfgn bdt sfga adrypo\n"
"ylah eedu rvwdpmq eedu ylah\n"
"quages kmla yjqua dzxcfam srjag wujmcv qujya ssaol uzdwi\n"
"gdsppz yqxlish yfkjbbf ecnzu ejvtv cdjwre\n"
"slsls pcmrq zax btrc kliv ntho gymkk kkq pcrmq mvnw sjfegpx\n"
"ryz jfw eki wvibww qdzylg whbagp ffrfjg wdhnqpm hcrz\n"
"tcjqfh tmvzp mpztv vpmzt\n"
"xood xutgof teqov fqyyub oakm rzaheiq\n"
"axagoq jawbz sexucp sexucp atenr edekcwn edekcwn agl ecj gbje gipivfq\n"
"poqv qopv bos flhghs gshlfh\n"
"rxd dzphnb bwmna vxd rxd sbk kuor\n"
"kqeelq jqbyh xczqzqe jbkmx kelqeq xqcfqn\n"
"jdfy qzjyz xvqyo jdfy xvqyo\n"
"vyoqyd pwayqag eygmdt smakwc veftikz fzeikvt\n"
"aozgkne mpd mktgoew eepp zlwycr eepp hswbxcx nmi ddnfr eepp\n"
"dgpfp cfhhqdx vjrb uyimbm byx hfdhxqc\n"
"fxq jcouwfy uhuao zsab xjao\n"
"noudveu egxyuqw hmnnv vovt wmqkx syatiac whkd\n"
"gxyzk opgb kjxp delavq hsnvk kfn irkcfq lvc aadcwy opgb\n"
"exuiupk ddiiyvm nsggpj ddiiyvm nsggpj\n"
"hhjby rfejzp akxzs nconlt rynivtq voloj qwhhll ubvx yxuacz miuwxh ppe\n"
"uspqvx supvxq cekv niddfuw\n"
"optzcag sra ajs ozacptg yxkludq jjpvldz mxo mox\n"
"dko qyec iuxbrbj dlz jxribub\n"
"ywlyz vipfh amsfr fwiozi tahjov tap rsea zwlyy oqdyfbo\n"
"xeqml jwy eguc bvzvh\n"
"crp mxsihvo wwtg gsypx mxsihvo qpfw looca gewvy zjqki tdkuxo crp\n"
"mqlnzm yihsvrl hhtwcv kigymqu yswki hksk vbiujq xeqz irzcq cpnz\n"
"zxhfsw uuyhwid nzabem mmfk wszfhx shxzwf hqnrvsq\n"
"hfjajdl qwmk hjdalfj mwkq gqbku dsszk\n"
"fbiy pujq htgaqqq yro ztpe yiufb fnpi ggchdgz\n"
"sixq jsboan eoie msdrwzw sixq njsrc sixq yimqoi\n"
"pbxgv kqmi hjuk bbtrlta bqwm bgehofj ainqhm qoypsil manhiq ogebhfj lvmuo\n"
"wnax aen fthpcke tcz yadjmva mydavaj rcfkc krfcc\n"
"lkatiw zxliii usdj oopxl yylv bkjfy gtlyjv usdj muqazdb\n"
"yqonaxv wqnvoo hfpll oyxnlfs fgajc khhtzr hfpll gsvvipz wbjxsnp dcdikt hqw\n"
"vvuv kspmnz zvmryqd egvuz eazkhz kspmnz\n"
"xgq dziwiym gsl nbzmsta ccbzn yalof dbbugq aar ywmbvk yofla dcwb\n"
"qrtyhhw xeyo vlym ulzzbl hrxyb qeyu jqdkewk oxye evaxz kybc bssyt\n"
"eqrf cfyy kwhohw ozg jsc egz jsc\n"
"vct cet ixxvmz ibhvndq eks dpi jzfwdqv saeh jqzdfwv vwfdqjz\n"
"vus vus kitvvgq wpi alfncf gzj oxcy fith oxcy ecbsr\n"
"uacculk guwhwdp cankcv yswy bmby sve dvonm nran\n"
"ydftm wszgaex rgbw otd dbet lhsxndd jqfyx\n"
"vhawg hwagv uagy fveik nrsew zujw hawvg dzfmt agzgw\n"
"uqdj talb uqdj aizyuqm\n"
"pbbejee szdtohv tycfow xwne qzlqy dxcwejz pqdqrc wfyotc gdqt uxaeug wtldm\n"
"hmzmd oyp pyo opy\n"
"qwdh kwpll kwpll zsbez uxg klr uxg\n"
"myqr zza kqpcos adsql eumunrv qlaeumx\n"
"acyye xvdewe nwkhuz bzcmx asw ostiwk mfzu nwkhuz\n"
"memq uqadd kfj dses lrxb hxygp dsse bxbr hgpxy uavrar\n"
"mjmk lsdttuz qjkg yfthmkn pram\n"
"pctfq aly usim shihap uims xkfgp ksrbn ifvsyl\n"
"cdma nnnu hdm dhm\n"
"kpt upgsm ohvrrqf qwps wjcbve ohvrrqf\n"
"wowphgb nteme otizypb eumgvb puoctli opicult wbohwpg\n"
"fppz ftkql sbut lkqtf svif viqhlnn buts lljhbd\n"
"oqk uinby rqy vbjhf oul hzfo coca glpy brjy yglp qnvhvei\n"
"sbbwr dnyrux gpikv nsx aawyeq uhtucwq rhxzy jgx bdgdrl dnyrux lgfgi\n"
"agn mljz hgmglem popu jtapub agn\n"
"ehfpgr bnobvg bnobvg bnobvg\n"
"ozgzedn godezzn art atr\n"
"urz rzu xzyc rjhwi kgiodi doiigk layr dwbxu\n"
"rkcbav pnp bpsmm ifivfe csouqpw fyswzbd csouqpw bnjt rnnoxed\n"
"hpjgtcc ctcpgjh cchjtgp lxn\n"
"cinokbx uyaz uyaz uyaz\n"
"bphfwad bphfwad bphfwad yml izlhlb dvjvo jeropar\n"
"ocgftcl wshjk zbinw fcotlgc xdj nwibz\n"
"zbze hllno rmq invd gupoxr gwumc vnzj fcvvhjo dnn sfsxw\n"
"oqlhkz hgf yxiahks vhzvl ayshkxi irmwkmq\n"
"apeqic ahwu abxjrd tuwrd pynnil eohmlgo lafx ybpofe wbznxv swuafas\n"
"cpg jpsfo jposf rer ixeydpz\n"
"rhqrwvn wrhqnrv xptms jhc rnqvhwr\n"
"zfpl tukxzda lifkqtd ynfuno cttx ctxt tlqdkfi ueswv wbipfbe\n"
"eblw bwbjg fuu qqm qtv qtv isbl denfcb\n"
"ick yqwcffk pvcchd apkjyc ouu uyfe nplid ick caqscs sddkx\n"
"rtzh idn snnw xmlou idn kdhenl rtzh ujwttl pkynkhe\n"
"dnwha fpv dnwha iqi xggepo dnwha\n"
"yjvk saay enxqhw wigoah dzasyr nnt artl iqwia jpp xmfr hwigao\n"
"ryt heenuai ytr gqew hyb byh wdurx kmd adgjz\n"
"ypdqeji sfkkfhn stms cdmyh nqllx utiphia gxbx zflhtgo yurztx eni\n"
"pwlhlt lhlwpt rfkvlgr tucajej ckujc ntcyae xestygt eshmggk\n"
"gtfb codwc vjtli ffmjwx ruoekt cylrm ktroue dfaxzvs kkgejzi ewucgu jyatrum\n"
"ersbag cod xssha aqzbe kxu bzghhqk pbs bizvqk bhbbd bps\n"
"vhci ypxf bxzor unngl xilpzpk civh nykora vchi\n"
"cyb cceu negnld nbcfs pxsjgh xah nbcfs nbcfs jabpxg wtanv qhztvr\n"
"cljgzkn lrdeina hrjoz kdgpn vqkmpal nivk scvnu vzuausp\n"
"nif fin uxjbip xxztsn yyo opueh zxs qnso paedey hsd fttvqdn\n"
"gbnkmpr afo aof ryyudy gbmpnrk\n"
"uaa npb dkit npb buadan esv npb hwrj\n"
"hws dfgq fcyty qszhu chyxxl ytmpb azxl jrsn boqrx\n"
"hkzlnkd fkilvog xbubu fbgbp\n"
"fgi inmay uliytc vgkcw qsoe uliytc isjhix oyir ocaq\n"
"qrzkpm dpzetbr zommsxo cixg nwjyvp bet wyjpvn cgxi tsncd\n"
"uvlf lufv ulfv cigl\n"
"uwwf thr kdq fhjmty bvxue vcwwmk kdq nzajq bxkf\n"
"qcwduju idxaja qcwduju idxaja\n"
"fnarz pstzfne nco qzf kcevoo qwx csvsxga pstzfne\n"
"twug xrwy uoctfl bkh yxrw\n"
"unpdnbe apf cvm bpullu fyels tjpri jyw unpdnbe xfyekay vhk zpyb\n"
"rbv psirdv psirdv mnjrp qpwc vicismd qpwc\n"
"zjj zjj kesyhow eqcfqy vqy\n"
"zazpd gmea aobl dcs mage hqjdpwc bvxr srw\n"
"rhcdb nzsa jgcgc rhcdb wxs vsvvptn zvckqo wxs\n"
"unyet prchn fiwter wvgknes dvzbxfs ufet neuyt fczlrx bpocdci vdsfzbx\n"
"znfev fwrdarx knqkv ojiv ojiv fwrdarx\n"
"tbtlo hdashg kyspxm ypmkxs nmrk\n"
"fzr zqxaszt frz xzrre\n"
"shueb iraetk uhsv duvah uhsv zstysc nrfllbc emrknka\n"
"vzkrmp mgtkjnw njr bwjgp jdwyyhv yudha wbvmx ewu urhiioq\n"
"yjq xxr swvm aipdj apjid tfsq gfqg izrvhev\n"
"iljuqt fpo fxadit iljuqt iljuqt\n"
"zrj poewso vsje bsprbmc vsje yfwf ybu dmkqib ybu hlrpdi ymh\n"
"apxaeq bgdm mqty whyay mnuzfgk awm bgdm mwwi ekw bgdm\n"
"dpdbfkm crrg mkph kphm grcr ukbk\n"
"ilqm wroz mqil qlim\n"
"pnlx nwadw uabelu rueamxr wjer uwge jwer ywagrx\n"
"akuil nkh oitq werli werli\n"
"fkmhcr ieoj xfsa xfacoeb tcg poomcme vck zmpc djcqgkf kft\n"
"csyk qni hqfrye zyyxz ggynzad pjpokmu bigqa qie\n"
"lkpenw zyllii qtbvdq zqnu ichftg xazped agl irhlbiy snlwfe twliar\n"
"acsrba dzz ivylbl rfcdd rfcdd qcg\n"
"zbui fomvpx zjhmgl sivtffu xuhswzt fzeid tgj mzok mozk afbhuje tzswxuh\n"
"nupjiat fdxkbn tuatp jhdfnub yitdk yghqw nupjiat ibi edfv tuixw auwjm\n"
"focht mnprh tljj ayp\n"
"pjdnl uaoworh iqm gic dqlu spn heuymio\n"
"kvg ferrvhp unvzsd qdcpd rji zpch\n"
"nhvay chuzg pyhdd hnmrnq zeidhf pyhdd ohy hnmrnq\n"
"boa sau gxh grx\n"
"gwo utwpd zcsrx gow bnm\n"
"xoqniyd hmithl xoqniyd hmithl\n"
"yqqsbzo stca zcsjnqf skbueeu tlbkef mvqbg igzr wujuz yqqsbzo kkfe\n"
"wgzuepu wge fkrxuag csenx tkngoz wge azueyxs\n"
"get xiryxs xiryxs xiryxs\n"
"wammvx edy hahetl xmvawm dye\n"
"lscxxgi anmax quo cqprwn imocarq gnbfhe rcnqpw\n"
"znpmid yaluvzn ydm ckh uhso rrk wbby lwxsu\n"
"atppk byf dzz uift nqejgm njgeqm\n"
"dtqmy iog ahub habu\n"
"hkthdwt pfxlwsu hkthdwt hkthdwt\n"
"tsuiue tsuiue yais tsuiue\n"
"swooqmp rqrcs ngr vujrq inuu rqrcs\n"
"dhu zxdfiyv xuz xuz mgaty mgaty\n"
"kiiiz zco qdv vfgkj rders zco\n"
"trszp havbm redpeqk gktp ifvzvwl yfoxnm tzg avzd otiouso eks lqlutwb\n"
"cfiru lpdy kpeas mdc lxnjjqz nqyyb xkjsug rcifu dln\n"
"jga ijgkjo qhbnupb ofzqn iokjjg gaj lrh pkynrcr jgatk\n"
"bexwc tat tat otsngaa\n"
"feh mjxbs ehf cyfhlv vvdgdu hef\n"
"njlvq ojwaes awsejo ktyvxd qeyeze bpoaj ulgngn zyeqee kqc bsdzzvq\n"
"hbfp vnhs vnhs pko pxnxgm\n"
"bmy bzpn bzpn bcfep\n"
"cju nqjy yjqn bbrj esgzw swgl bjrb\n"
"cxvrshm rbglkyv kqwzcyd azqr ckwbbew fhgqv nfk lactzh ssqpwbr wbewbck\n"
"ptcb gqkb apcc okl jbbgk qni bqu slydyo qhh dqd osv\n"
"zbisefn bmxcljk bmxcljk arkamus vpq uxuwvb\n"
"ksik xbzk lahh ctfur sxh rduokr xqou zwbgqsp skik\n"
"hwhmfk hwhmfk bjpxzg qqftmu ijyv igvayf bjpxzg\n"
"askxqew tibx pqaczy fhzyec echzfy cezfhy\n"
"omzyy mbzfvsn kkoff qgqn crnnkn krx oqp jhn anb qte qxt\n"
"jypnwn vjbnbsl axf pldxbq pdoy rmxcvig cpad yhah rzqewkg nmzkkr erjo\n"
"visidzp bujlfn xuomjj mjnqn wgflg skb\n"
"oer oer lfi zyqnem lfi guljz\n"
"fannhwu wafma gcje cvcia qwyh ugtbpa geufqg\n"
"kwtjib pqwai tdmjj kuxr euzl rxuk\n"
"ovi splc hflutgw hflutgw\n"
"gvel gelv aeiygth elvg twwr kivxrrj jkmqa\n"
"bas ylxbdgn yliv pytkhq haujsyf fggrnbc wsgree rfnppcx key gvdzgfy evdtrrz\n"
"oblab wpgm bpyy xuroy qhb adqko\n"
"hneb law uzms fhhk yjymdx wjla ixfh yblh\n"
"qlvsd bxsq hjaq fuwspzu hyshq idbabc rqcih ilixp wft rglf lmqm\n"
"qdskj two ckd qdt hzjvd woo fmmuw\n"
"kumc zywzq srafcbb ihfu kfvav\n"
"qlkkrq qlkkrq qlkkrq qsc\n"
"hob bpecik zqtrfz iqizeu plrer epm zqtrfz xrekeql xrekeql\n"
"warszd sxyyorh sxyyorh eztjf warszd kszp\n"
"hjbrax liumjue liumjue liumjue\n"
"rfnqd folmiu dlicln pdyk uqd rfnqd\n"
"mjdu lytfvya xomdujn leaqiyc lgemz lihfnhv zgeml koukz luqda\n"
"yqsz zedjmwn aep qwbhd yqsz\n"
"etg rmovps abizj yqr kib\n"
"yznxec sfqkd ofkzep njr hmeym nsh xdq\n"
"ryoyq heoo zuo udvfev ehoo axcnbpu oeho mfenmd shrebzy\n"
"uaeh jwllsjp frkhqsy uaeh\n"
"giofw hwceb euikqp ldmb kqpkxwv namazcg hqyyzgs cglsqux\n"
"qledbd qledbd kbwo wgfmgp\n"
"olbsca muxw nxs locsba\n"
"gbxxgj xlzm gws pkpwy ofkxb sykhdo nbhrv\n"
"najr bfk tbqkm hxabe nvr mdi dmuujr bfil nyripr zcydzy\n"
"kiczhcn dfgylw yzkwk nytijj pceu yukj ekaol xpb uep\n"
"acyyxn rwczsud acyyxn payiek inusyb rwczsud\n"
"mzssokx bshs bshs ocrvlug nzsgvch riejkrd jkj mpmdgsp kvixdfq msmmx\n"
"uaxy wpvhf uaaq ranp vfhwp iik kii nvh\n"
"shecxef nqpx jly dzm qvmpu kxg hdg\n"
"xembm yzevult ljrllc yrlskyk zas wstnz yrlskyk vasra\n"
"yoaxppi kzax hvxfezf mek teo cbtlrfa ncxac yee\n"
"dzfpbi cynov dje vxypba wcwww cwnu cqtp cnuw wwwcw rkzas\n"
"xzwdt jcwv anb xzwdt\n"
"fodgjem fmmrsfl eovsneo etzutda paw fmmrsfl jcqql\n"
"yfztt alcw nwdmd afgknu njxkj zykz cvv jbnl han iatmruu trqls\n"
"yas hpulrmf dzts sltg qsbw fjj rjymnnx dkkv\n"
"hwjtgd abmb cfw xoumxn xnoumx cxo xnxmuo alb\n"
"hnl zgdiip lrddhl fyw mporhtp waedf dltdfmc lyipoth ubmg hnl\n"
"wxard wxard cibp nzquvb muuslvw igvewfh mika wxard\n"
"cjqjhva rrhzy qpdc nqnyd enbdee ewrhp cqdp xekgjai\n"
"axtmxb axtmxb phl urdqaar urdqaar\n"
"umce jult bkart dgdvdwc kqzlzn nqkzlz umlxx cmue xvehqag wxifal\n"
"lwsuc ski ubo ksi sik qwcudv\n"
"husdv tssr gfp bfzbrp jtmk svvdpb uvshd zbnpdmj svpdvb\n"
"nnbvf xbb dobqk xwloqca uxvqti blcwxpu kubwu nognin goywn\n"
"xhe dhddftc ggltd dhddftc wspf\n"
"jodq cgvnk lpl wkwwlqd prfby bpyfr tbgyqm\n"
"bdebxj cuvow jdwdxw kuzh dvxmsyb dyvcxo psf kjnoe odfwgfa\n"
"xpfb knzgfsi thmsnbi ymjxn bevohy xpfb\n"
"hphcu fjodpdt mfsp jkvvp jvypar nlud lfv uftupcr nul dunl\n"
"olz ihyhw qntr lwcbohv qntr wzralwl\n"
"kfz pkjhidy msnmwz exox xexo uakipj mmznws zbbji ozispqb\n"
"gfi kwdhx qqo kdxwh fig\n"
"ehh rfozwr caoisw qntlk pkv zulc kpv hrqz\n"
"exmlrj aacc rzb qie rzb\n"
"mxyqe cuqz feyd meqyx gdvpu rqyjtvw dmoo vugdp emem\n"
"advj xmnad uvh ufnbi xmnad xmnad zzwjksx chbrjas hrbp ruvyg\n"
"nasrghk pmol ryko ofgakhd korf vpy nakrsgh\n"
"mylyqg aeizp rnk krlwchk aaqg\n"
"edxursp sosyv zesgnpx zlo sly alurdc ypmez qib aqtt lmxd\n"
"ihm hwzhd jhiw raocjk nlxce yzuzu nhudri tvygl tmclg mdkz\n"
"psubdis qrmxebg kdac xvl raxwfx vlx sxme\n"
"tci tphdy tggam vqqiyjz sgfvdri sxhztz fhsmxx yaj ncxcxq tic\n"
"xkljs cuhrm fdjqwd fuzyzh dzuzgjd lzpye lzpey\n"
"jriwl ypkcxd fxrg eit okzzzsc yaykarm qzuv jurgek dzfbbfl\n"
"workf rrw absfl gxluw qprdsz absfl qwqbmi amepvz oiqmy workf\n"
"dxyyb brnerbx lykd oqmz ursl zqom\n"
"cqtuzva aih uhaswd auhwds ktyvc hufogcg\n"
"jre fhlgrse svedc prfspaj ghm qcjzfc nsd\n"
"fow xyo vlvg sgg jgzvff rjxh eovre xtupnz\n"
"pekj pgiecc igxd zbiqoob ovv\n"
"xofxmz rdzdiq yruoqkh arfunx yruoqkh ucm bxov\n"
"ctogwj lpv ivtoxkf faj ctogwj xfzluad ctogwj vvw\n"
"rmc vjxj strgo tykifpp\n"
"ulivozu bczond ywnmt shakc yknr psr\n"
"bfx alwedh jfomlf pzj tely alwedh vccsoer rgwftcl vccsoer\n"
"frkwbv uudwt qsfg onuhiml jrd usu\n"
"bgdx deybefo gdj dgbx luu cbuwawd wqqtq dqmwy gin mhtfgy\n"
"ohjp ykemg nrs leayrh brtipx jhop phoj\n"
"utaep ywsy utaep ywsy\n"
"qow dxagjwb qbki bqik\n"
"larkpq bdgw mly vvwgv\n"
"juar zaerof qekpe hhgd eygru epekq dhgh\n"
"xpblz xksc lzue xksc yid nnve trlndn gjczngs cifqoaf\n"
"fpv ekz eknldf uqjgeu awwnwxu eknldf eknldf txhxv\n"
"mzvk wqtbda ovdbh vnes uiuuc uicuu bpwwtm aaat cygej nio gnl\n"
"rkdkzp bjaxqif xuwx bjaxqif hgtz slkqw rkdkzp ztp xfvgk ycvg\n"
"zpwr wvxzfcd opgcrfc ytxeboe rcqa ehrga lmgm\n"
"brsdnk nqgkjab nbjkaqg gho zqe\n"
"szbysu oqrtbp wjpuv oqrtbp oqrtbp gjmqq\n"
"uoyi ctscw uoyi ggn ija\n"
"fop lxa cgwpw lyvrxbe tit fop fop kfigqnu\n"
"ldqmk rxo ajhrbc ahrcjb xqdk kdxq\n"
"ith vdrl kvaxktm grkzmon ith ywbz kmnoiz\n"
"zdoo omjo fbz dveiipw fbz\n"
"ivj mcnu tkijlq xkq lrkyit cumn sfkrk numc ezxeeoi\n"
"lcwzdi sbsdgdy olvc olvc bimubzf bimubzf\n"
"cdjd umhwh djdc cddj oxheq veazlm\n"
"gxszn zsgxn azy yaz\n"
"byvmj mjybv jvxkuy akas uxyjvk\n"
"whmkttq whgzm gwmzh pkvtljw zgmhw jasudeq\n"
"yyjri fxsj xffmna vbal ftff rwq uszym bznil rfuctp ejndv wqr\n"
"gnwzjbw dezfvq gzkhzkl ivrdvxx wfah xvivrxd qzdvfe\n"
"xnfo zqzn iaod zlcclsd onxf lpskrfk nzqz kqzr kffpwak eky\n"
"muc tafbzp nra gvzc xiu gvzc\n"
"gfnbnyj nyjbfgn eoosw yjzf\n"
"qwwls sqwwl mxph swwql\n"
"twor uzjftq twro orwt\n"
"qomjuob bqaim zvfqww cvqzm wwipc zsywb bsqkp aoj fus\n"
"nlyd gtbgox tajlzgs bgtgxo pqt\n"
"pjtmgz ulblj ussh gngagba hhtexq bjbj obe xctciay osriw obe shxri\n"
"agc ejjdtak jgq moj agc iua syhxih znavmrc iih qubj\n"
"zxwzwhm lipkqhz bbv birxsj gzg iefrjh mprsfs ofpltbl gbo srpmsf hirm\n"
"rbpgqoe kymrf uzsut gkbtd xctpg qul hirtfl\n"
"wfvg pnqhuv jayjm ftqt mbrotl aydmoc lfwlxk vpvcsi svbn bnsv\n"
"jxjxza ysl kls vmt fvgunx hketl oshgie\n"
"dfeyxv akx qagwayp qrs lnulrle rqs gbvd bvdg\n"
"aac ndptml oke edwrg aac xechxz\n"
"mpx yrb oervzb ydvkw avlt oervzb bxdqbo hzwls\n"
"dsynfk dsynfk epexzjd epexzjd zofb\n"
"vhe zxfolqk lkh fxt flzkxqo lztwkmo khl\n"
"izlthi wtokkuz ousbpxp pvr uuxueq lvbeff mfk syjq fwgnfmg yytqesm gdd\n"
"kjcg slt khz atzw twpspdx kgyk wgq hjat ntf xvhxol msvdjs\n"
"ymm arrggw mmmbvrs ist arrggw nbvvc cwyacp\n"
"kuzglex iemp iemp jsko iemp oqs dheqypr\n"
"tzztq dsxqbow qgaeo kqn dsxqbow qqzpv\n"
"ysr fctpiyn psgb gatavv zsfxoxq nynfoh qaimoj zotjk nxug syr\n"
"xvm qvr hdxyhpf cbo xmv lfv wltyjlx\n"
"hjq pohc xgqit tducggu zdqmnc xqgit tqxgi srfyzu vdikqx\n"
"msiqte ewvp bzrv cmuy gse qqayvb bzrv qehy\n"
"watdvu ametrc etlduhh vcc luehdth udavtw\n"
"jktj mkq jktj mkq\n"
"uekth ufjkmdi qzhge wzwcwk nvrodcc vrcdocn bhcvd\n"
"xumywk zwofh kuxmyw acgzsjj hfowz njnz bnklyi\n"
"hmm fexu fexu hmm\n"
"zeuoarc yoa ggff jazzd mjein yhj qwo qwo\n"
"rolkwf fcyat lwm wqqm juwkt wqqm udj tex xgps nyy pdbkkhb\n"
"gld ksl gld bnsuhqc gld rwmybj\n"
"tvyxk xgmk cri pef epf unsl yktxv\n"
"muiql ejq taetjkf ejq xzmo wmv qbtmrh hkfbch taetjkf sut\n"
"pqg icvv gpq tufd iixd duft\n"
"zekx ybbb gzml vrbwcl opfb fkrv tto cbipr\n"
"moh stkkf ynrtdf jlgb kstfk ksktf\n"
"nvysvf mdtdoq bqqvr bqqvr\n"
"dqyz mzoqtp gzhdgd symsq iwh bpwox\n"
"pkqi jgzsrah yfjxx kdp xjaf lbj gkpixnj tyvzzso qmjbo skg nlchzbk\n"
"culxfx jarwu eiwriu vwvg gvwv sgnasz\n"
"kyfsn dwc sbnoe xwpgjh nbmvec dwc qjdh mpw gefimue fvqjwt kkor\n"
"hcdcgxs fof flc hfpjy lii fihcao pxg xywei jwsq yxr\n"
"oxrcv pda oxrcv gdvojsz kmlga mixlmp hdcabsn qvoa fwt\n"
"poe joylchz humrjy cyxbqfm lyk ybrfmp qmtpqyk vtpr lyk vtpr\n"
"ffswqs yxbuj tfzkmc yxbuj giog ckubbfy rtigw rtigw rpitxd\n"
"kcvrn eejyftw ejytfew rnckv\n"
"lvk lkv cooumh vlk\n"
"loypv ukowl loypv nyoyfl vehnm uff\n"
"tst sei zovy itdwibj mcbtst wcf rzp xvbtax ffzp xieenuy aegkj\n"
"zkhi hvsbgza xbwtdns wypfngy lvabd pybhcd crczm buikdpo vqgon pynfwyg phbcdy\n"
"ihy irxrj entmc yxfhbta xsdv xsdv\n"
"ezrcv kfgm pjneez puccy gzpxdlf gkfm yucpc mli xezfug\n"
"umjppkq idkiri wmnbhi unl nteyw wmnbhi zyv idkiri shhcrau\n"
"dzj zveqwae ljnikvb baavr dhsohp zveqwae goq zveqwae\n"
"xhc xch bmttdr snd jakd\n"
"jmgnvda bdpzfw dfwpzb pimpv blqtbyo lzdzo bgrlfy anmjvdg\n"
"lwvu ksg gqbtibd ksg lwvu ohfzlt foajo apyrcwj uaro\n"
"vel qksrwp zei ipnvd hdua rkspqw bujf\n"
"iozkiu upa knmcug zidypn yswb zswkvx naqsu\n"
"tjktoe dqpt pbqi dqpt\n"
"lcl tui uoizm xrdpmwi fbsuuqq tgeac hpajm tegac nczlic\n"
"ntmm mskzb arem ntmm jayzfe wyurgsh eqwcqt edhska asxhjv jayzfe\n"
"jyq juifidx fokzxh cgo xofhzk nhro xyccuq ioa nwk nqaxpfw\n"
"cvag bpk cuo ocu buehhq tartafi ifs qwh cveurg\n"
"bwut xpfni qzg cmp cid jftawv twiszmo\n"
"zgxc sui kypkd vpam ymxicrw jcfbutd fgx jcfbutd\n"
"tkxn rjqzljh tkxn mdwcho\n"
"qbv zneocv zneocv zneocv\n"
"tywf soncr lyepx qzj xdsr pdqv swt\n"
"ulu rdk iomqu dgouoba icax\n"
"ddsc oxilqpd ddsc atbekg ouzmxf oxilqpd kwtzz yhmyd otvi\n"
"vtj llnfrpc vfighju urosrsz vurtse llnfrpc qeuo vfighju nnn smsnp tfom\n"
"updfjmz ngtgi zaitq rqqhcyn ladzx zaitq fbaphyz hipe\n"
"rii fpos atl tal qhubqdv lat\n"
"whxzwdj yznkngr eefbmub wnxitd tnwxid zja ziewilm xylwn ihhsha lrptuyf\n"
"fhmzaxv mdn udl gyv pqw qlrz flm rqtji\n"
"bgn clnm cnml qyh hhf qqnur sgvigvm\n"
"qjtbysc ycbqjts gbgvlz vgzlgb dgxks qbvp grji dcc\n"
"wmduuq qayymzo zvh ylbipw sin ybwpli ilypwb\n"
"qsvzktt qsvzktt dasmg knh gcgep qai\n"
"jxukj qlgr cjssj aavqv\n"
"xpxa glsdfxq ngxwon ytuue pizqu\n"
"fxl vegoed tct luwm ulwm eeovdg\n"
"ntmpe auasx vkwgi cryuiix dmiufo fcb ldl jauncf gyouym asjcryc\n"
"lgwdcs eoxm hcrpnuf pcfnhru vlye fpurcnh uquukv vjc\n"
"lfns riwpdh phwxvew hhu jfptvv ofxd hkotgfq\n"
"qvuwnq wnpvs xdivrfz yaenqr fipwgl\n"
"vhcexfd bishqsc gsbruxm yzccyot yjloa aptg vbr gsbruxm ihqhyz yzccyot\n"
"knfst zhihi swhhq zhihi\n"
"qfto abhjx abhjx bpnijn ogmqxn rclqag dmeb rdogx emfriui hyvp ogmqxn\n"
"ivaemm wlsc dvjv aivemm xvf shfonv\n"
"vowhosr vptlu ucrut rdynh ttqvhg rdynh abtja pnvdy puxfmf dyhd\n"
"uvrenol ycuhvy ygm fjsxiwo oftstid ygm\n"
"fix qrqeg dfgvlun fix iraxgtt lhgqdo eqkgshd jwmrm qrsbzba\n"
"mxdj icjqzqw fvew gtvlhm mxdj\n"
"cyjtkm crb pmg jwo iluc brc ttnd\n"
"dasmgp ool ool opc\n"
"ubi pmz mtkh ibu hlx ipcvjki sydw zpm eewfdeu oga\n"
"avex yjaoghv yjaoghv lwwx\n"
"kwkdst iuokd nmpw onayet zlavwnd wwvbr jtrkyku wfxx dumydgh gnd zgi\n"
"ahyjnc rjakp bhabq tsmfi ahyjnc tsmfi yitqgi uwnywil shnkbn\n"
"krr sbbfjtm yvunas hwppsjf ntuuzw ngyvdmt ynk nfq mfrb pyw hngr\n"
"eeecesf phoo ijmx sjp kgmtg sjp wyz\n"
"qwixmou oximqwu ixu lsmf\n"
"dyrzq lbstdjv ldvowml qjf fqj zpabc dwmvoll jnq\n"
"pdtlu hgcfvz mnwjyq ymi cvcp kmx mkx ooffp uiwg opoff uevqt\n"
"hflomt fhlmto gutdbyp xyi zpggxc wqe\n"
"jpsr wwex yjgdj fqah wrmmw nyrnw hcomcgv teajmu emw zrraid\n"
"tvgsca bzgzkga ypsxsk dqz exmu tvgsca dqz qnd\n"
"arzn hojpi bznw ejuupe bznw hojpi\n"
"rids dule qaefaon sspit mtzgdls cfujw xldhimi igdoy dule\n"
"nefsys plea obksngc zxqee avsi obksngc vnsxdrl gspadob avsi owmzpeh tcj\n"
"oweq fkr krf rfk ztwjdry shzcmew jhna\n"
"hdjizhg dfclic usds luz mcwyj luz qvomls mren otax\n"
"pmzzfj pmzzfj wfxyq mqv hyp lhf\n"
"dxeaw ckkey ccvawo keaf izlh oacvcw lgcpgeh kdiky\n"
"xkwe xekw kwex tzfyx\n"
"dmmyt mtdnqw pdw vdav ofrtsk\n"
"klz zlk snxnihg snhigxn zkynpd\n"
"ijzce xobf uojezxi xiuojez\n"
"ztepv zvpet nije aditjlg natkkk dtitg jprgia\n"
"fesuh wadrhc bayf kktfaf nxvhq smbdaop gqx ioez fkjufb abyf\n"
"hej sta pztkcd pesabzz szp iada iada cdae hej sqst luf\n"
"xlnuhn oljaf fljao ascxez fojal\n"
"dprclb fzn wgauz rxewtp cjrlgz zfn\n"
"fidwoa mvoqy afian ntzokap mkplgy jfukgjv cyfsz\n"
"hbvqnnt giinuzq uezugy qooxjc zsxr rnihg ipbels\n"
"qroi wtltjq suj tqit bxtc jidzhpe nizp wtltjq nadcdm wwyhjrg\n"
"qtr fkbl bpptu baen awjpwsg vvqbxz animt uqbk zvbxvq\n"
"nznq fdiul jbv umyrf yufrm hrl duilf\n"
"bkvlfuw onkqzeo iwrg rifqzhj mgroul rnor qqqc sbfi hny zosfp kopxb\n"
"nvifbx jbowbj fnyskt jbowbj xvun xvun\n"
"piyl haajm stwzpp xvjg amjah\n"
"gye efwwwiv kyv zmtcgmi ifwvwew\n"
"dflx gdtb jyoj jyoj dflx aqhycgi xffnn\n"
"inc mpys mzqmcwx vryz ibqrzc pmsy fat rojpxwy rcbqzi gjef";

	stringstream dayFourStream(dayFourInput);

	vector<string> dayFourRows;
	int rowCount = 0;
	while (dayFourStream.good())
	{
		string singleLine;
		getline(dayFourStream, singleLine, '\n');

		dayFourRows.push_back(singleLine);
		rowCount++;
	}

	cout << "Day Four" << endl;
	int simpleValidatePasses = 0;
	int complexValidatePasses = 0;
	for each (string row in dayFourRows)
	{
		if (passPhraseValidator.BasicValidate(row)) 
		{
			simpleValidatePasses++;
		}
		if (passPhraseValidator.ComplexValidate(row))
		{
			complexValidatePasses++;
		}
	}

	cout << simpleValidatePasses << endl;
	cout << complexValidatePasses << endl;
}