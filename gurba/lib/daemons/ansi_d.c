#include <status.h>

#define MAX_ARRAY_SIZE status()[ST_ARRAYSIZE]

#define ANSI_DATA "/daemons/data/ansi_d.o"

#define MAX_RECURSION 5

#define ENABLE_TERMINAL_CACHE
#define CACHE "tcode-cache"

#define BLACK 	BOLD_OFF + "\x1b[30m"
#define RED 	BOLD_OFF + "\x1b[31m"
#define GREEN 	BOLD_OFF + "\x1b[32m"
#define ORANGE 	BOLD_OFF + "\x1b[33m"
#define YELLOW 	BOLD + "\x1b[33m"
#define BLUE 	BOLD_OFF + "\x1b[34m"
#define MAGENTA BOLD_OFF + "\x1b[35m"
#define CYAN 	BOLD_OFF + "\x1b[36m"
#define WHITE 	BOLD_OFF + "\x1b[37m"
#define GREY 	BOLD + "\x1b[30m"

#define B_BLACK   "\x1b[40m"
#define B_RED     "\x1b[41m"
#define B_GREEN   "\x1b[42m"
#define B_ORANGE  "\x1b[43m"
#define B_YELLOW  BOLD + B_ORANGE
#define B_BLUE    "\x1b[44m"
#define B_MAGENTA "\x1b[45m"
#define B_CYAN    "\x1b[46m"
#define B_WHITE   "\x1b[47m"

#define RESET     "\x1b[0m"
#define BOLD      "\x1b[1m"
#define ITALIC    "\x1b[3m"
#define UNDERLINE "\x1b[4m"
#define FLASH     "\x1b[5m"
#define REVERSE   "\x1b[7m"
#define BOLD_OFF  "\x1b[22m"

#define HRED 		BOLD + "\x1b[31m"
#define HGREEN		BOLD + "\x1b[32m"
#define HBLUE		BOLD + "\x1b[34m"
#define HMAGENTA	BOLD + "\x1b[35m"
#define HCYAN		BOLD + "\x1b[36m"
#define HWHITE		BOLD + "\x1b[37m"

#define CURS_UP    "\x1b[A"
#define CURS_DOWN  "\x1b[B"
#define CURS_RIGHT "\x1b[C"
#define CURS_LEFT  "\x1b[D"

#define CLEARLINE  "\x1b[L\x1b[G"
#define INITTERM   "\x1b[H\x1b[2J"
#define HOME       "\x1b[H"
#define ENDTERM    ""
#define SAVE       "\x1b[s"
#define RESTORE    "\x1b[u"

#define MXP_OPEN	"\x1b[0z"
#define MXP_SECURE	"\x1b[1z"
#define MXP_LOCKED	"\x1b[2z"
#define MXP_RESET	"\x1b[3z"
#define MXP_TSM		"\x1b[4z"
#define MXP_LOM		"\x1b[5z"
#define MXP_LSM		"\x1b[6z"
#define MXP_LLM		"\x1b[7z"
#define MXP_ROOM_NAME	"\x1b[10z"
#define MXP_ROOM_DESC	"\x1b[11z"
#define MXP_ROOM_EXITS	"\x1b[12z"

/* Extended ANSI */

#define EXT_1 "\x1b[38;5;1m"
#define EXT_2 "\x1b[38;5;2m"
#define EXT_3 "\x1b[38;5;3m"
#define EXT_4 "\x1b[38;5;4m"
#define EXT_5 "\x1b[38;5;5m"
#define EXT_6 "\x1b[38;5;6m"
#define EXT_7 "\x1b[38;5;7m"
#define EXT_8 "\x1b[38;5;8m"
#define EXT_9 "\x1b[38;5;9m"
#define EXT_10 "\x1b[38;5;10m"
#define EXT_11 "\x1b[38;5;11m"
#define EXT_12 "\x1b[38;5;12m"
#define EXT_13 "\x1b[38;5;13m"
#define EXT_14 "\x1b[38;5;14m"
#define EXT_15 "\x1b[38;5;15m"
#define EXT_16 "\x1b[38;5;16m"
#define EXT_17 "\x1b[38;5;17m"
#define EXT_18 "\x1b[38;5;18m"
#define EXT_19 "\x1b[38;5;19m"
#define EXT_20 "\x1b[38;5;20m"
#define EXT_21 "\x1b[38;5;21m"
#define EXT_22 "\x1b[38;5;22m"
#define EXT_23 "\x1b[38;5;23m"
#define EXT_24 "\x1b[38;5;24m"
#define EXT_25 "\x1b[38;5;25m"
#define EXT_26 "\x1b[38;5;26m"
#define EXT_27 "\x1b[38;5;27m"
#define EXT_28 "\x1b[38;5;28m"
#define EXT_29 "\x1b[38;5;29m"
#define EXT_30 "\x1b[38;5;30m"
#define EXT_31 "\x1b[38;5;31m"
#define EXT_32 "\x1b[38;5;32m"
#define EXT_33 "\x1b[38;5;33m"
#define EXT_34 "\x1b[38;5;34m"
#define EXT_35 "\x1b[38;5;35m"
#define EXT_36 "\x1b[38;5;36m"
#define EXT_37 "\x1b[38;5;37m"
#define EXT_38 "\x1b[38;5;38m"
#define EXT_39 "\x1b[38;5;39m"
#define EXT_40 "\x1b[38;5;40m"
#define EXT_41 "\x1b[38;5;41m"
#define EXT_42 "\x1b[38;5;42m"
#define EXT_43 "\x1b[38;5;43m"
#define EXT_44 "\x1b[38;5;44m"
#define EXT_45 "\x1b[38;5;45m"
#define EXT_46 "\x1b[38;5;46m"
#define EXT_47 "\x1b[38;5;47m"
#define EXT_48 "\x1b[38;5;48m"
#define EXT_49 "\x1b[38;5;49m"
#define EXT_50 "\x1b[38;5;50m"
#define EXT_51 "\x1b[38;5;51m"
#define EXT_52 "\x1b[38;5;52m"
#define EXT_53 "\x1b[38;5;53m"
#define EXT_54 "\x1b[38;5;54m"
#define EXT_55 "\x1b[38;5;55m"
#define EXT_56 "\x1b[38;5;56m"
#define EXT_57 "\x1b[38;5;57m"
#define EXT_58 "\x1b[38;5;58m"
#define EXT_59 "\x1b[38;5;59m"
#define EXT_60 "\x1b[38;5;60m"
#define EXT_61 "\x1b[38;5;61m"
#define EXT_62 "\x1b[38;5;62m"
#define EXT_63 "\x1b[38;5;63m"
#define EXT_64 "\x1b[38;5;64m"
#define EXT_65 "\x1b[38;5;65m"
#define EXT_66 "\x1b[38;5;66m"
#define EXT_67 "\x1b[38;5;67m"
#define EXT_68 "\x1b[38;5;68m"
#define EXT_69 "\x1b[38;5;69m"
#define EXT_70 "\x1b[38;5;70m"
#define EXT_71 "\x1b[38;5;71m"
#define EXT_72 "\x1b[38;5;72m"
#define EXT_73 "\x1b[38;5;73m"
#define EXT_74 "\x1b[38;5;74m"
#define EXT_75 "\x1b[38;5;75m"
#define EXT_76 "\x1b[38;5;76m"
#define EXT_77 "\x1b[38;5;77m"
#define EXT_78 "\x1b[38;5;78m"
#define EXT_79 "\x1b[38;5;79m"
#define EXT_80 "\x1b[38;5;80m"
#define EXT_81 "\x1b[38;5;81m"
#define EXT_82 "\x1b[38;5;82m"
#define EXT_83 "\x1b[38;5;83m"
#define EXT_84 "\x1b[38;5;84m"
#define EXT_85 "\x1b[38;5;85m"
#define EXT_86 "\x1b[38;5;86m"
#define EXT_87 "\x1b[38;5;87m"
#define EXT_88 "\x1b[38;5;88m"
#define EXT_89 "\x1b[38;5;89m"
#define EXT_90 "\x1b[38;5;90m"
#define EXT_91 "\x1b[38;5;91m"
#define EXT_92 "\x1b[38;5;92m"
#define EXT_93 "\x1b[38;5;93m"
#define EXT_94 "\x1b[38;5;94m"
#define EXT_95 "\x1b[38;5;95m"
#define EXT_96 "\x1b[38;5;96m"
#define EXT_97 "\x1b[38;5;97m"
#define EXT_98 "\x1b[38;5;98m"
#define EXT_99 "\x1b[38;5;99m"
#define EXT_100 "\x1b[38;5;100m"
#define EXT_101 "\x1b[38;5;101m"
#define EXT_102 "\x1b[38;5;102m"
#define EXT_103 "\x1b[38;5;103m"
#define EXT_104 "\x1b[38;5;104m"
#define EXT_105 "\x1b[38;5;105m"
#define EXT_106 "\x1b[38;5;106m"
#define EXT_107 "\x1b[38;5;107m"
#define EXT_108 "\x1b[38;5;108m"
#define EXT_109 "\x1b[38;5;109m"
#define EXT_110 "\x1b[38;5;110m"
#define EXT_111 "\x1b[38;5;111m"
#define EXT_112 "\x1b[38;5;112m"
#define EXT_113 "\x1b[38;5;113m"
#define EXT_114 "\x1b[38;5;114m"
#define EXT_115 "\x1b[38;5;115m"
#define EXT_116 "\x1b[38;5;116m"
#define EXT_117 "\x1b[38;5;117m"
#define EXT_118 "\x1b[38;5;118m"
#define EXT_119 "\x1b[38;5;119m"
#define EXT_120 "\x1b[38;5;120m"
#define EXT_121 "\x1b[38;5;121m"
#define EXT_122 "\x1b[38;5;122m"
#define EXT_123 "\x1b[38;5;123m"
#define EXT_124 "\x1b[38;5;124m"
#define EXT_125 "\x1b[38;5;125m"
#define EXT_126 "\x1b[38;5;126m"
#define EXT_127 "\x1b[38;5;127m"
#define EXT_128 "\x1b[38;5;128m"
#define EXT_129 "\x1b[38;5;129m"
#define EXT_130 "\x1b[38;5;130m"
#define EXT_131 "\x1b[38;5;131m"
#define EXT_132 "\x1b[38;5;132m"
#define EXT_133 "\x1b[38;5;133m"
#define EXT_134 "\x1b[38;5;134m"
#define EXT_135 "\x1b[38;5;135m"
#define EXT_136 "\x1b[38;5;136m"
#define EXT_137 "\x1b[38;5;137m"
#define EXT_138 "\x1b[38;5;138m"
#define EXT_139 "\x1b[38;5;139m"
#define EXT_140 "\x1b[38;5;140m"
#define EXT_141 "\x1b[38;5;141m"
#define EXT_142 "\x1b[38;5;142m"
#define EXT_143 "\x1b[38;5;143m"
#define EXT_144 "\x1b[38;5;144m"
#define EXT_145 "\x1b[38;5;145m"
#define EXT_146 "\x1b[38;5;146m"
#define EXT_147 "\x1b[38;5;147m"
#define EXT_148 "\x1b[38;5;148m"
#define EXT_149 "\x1b[38;5;149m"
#define EXT_150 "\x1b[38;5;150m"
#define EXT_151 "\x1b[38;5;151m"
#define EXT_152 "\x1b[38;5;152m"
#define EXT_153 "\x1b[38;5;153m"
#define EXT_154 "\x1b[38;5;154m"
#define EXT_155 "\x1b[38;5;155m"
#define EXT_156 "\x1b[38;5;156m"
#define EXT_157 "\x1b[38;5;157m"
#define EXT_158 "\x1b[38;5;158m"
#define EXT_159 "\x1b[38;5;159m"
#define EXT_160 "\x1b[38;5;160m"
#define EXT_161 "\x1b[38;5;161m"
#define EXT_162 "\x1b[38;5;162m"
#define EXT_163 "\x1b[38;5;163m"
#define EXT_164 "\x1b[38;5;164m"
#define EXT_165 "\x1b[38;5;165m"
#define EXT_166 "\x1b[38;5;166m"
#define EXT_167 "\x1b[38;5;167m"
#define EXT_168 "\x1b[38;5;168m"
#define EXT_169 "\x1b[38;5;169m"
#define EXT_170 "\x1b[38;5;170m"
#define EXT_171 "\x1b[38;5;171m"
#define EXT_172 "\x1b[38;5;172m"
#define EXT_173 "\x1b[38;5;173m"
#define EXT_174 "\x1b[38;5;174m"
#define EXT_175 "\x1b[38;5;175m"
#define EXT_176 "\x1b[38;5;176m"
#define EXT_177 "\x1b[38;5;177m"
#define EXT_178 "\x1b[38;5;178m"
#define EXT_179 "\x1b[38;5;179m"
#define EXT_180 "\x1b[38;5;180m"
#define EXT_181 "\x1b[38;5;181m"
#define EXT_182 "\x1b[38;5;182m"
#define EXT_183 "\x1b[38;5;183m"
#define EXT_184 "\x1b[38;5;184m"
#define EXT_185 "\x1b[38;5;185m"
#define EXT_186 "\x1b[38;5;186m"
#define EXT_187 "\x1b[38;5;187m"
#define EXT_188 "\x1b[38;5;188m"
#define EXT_189 "\x1b[38;5;189m"
#define EXT_190 "\x1b[38;5;190m"
#define EXT_191 "\x1b[38;5;191m"
#define EXT_192 "\x1b[38;5;192m"
#define EXT_193 "\x1b[38;5;193m"
#define EXT_194 "\x1b[38;5;194m"
#define EXT_195 "\x1b[38;5;195m"
#define EXT_196 "\x1b[38;5;196m"
#define EXT_197 "\x1b[38;5;197m"
#define EXT_198 "\x1b[38;5;198m"
#define EXT_199 "\x1b[38;5;199m"
#define EXT_200 "\x1b[38;5;200m"
#define EXT_201 "\x1b[38;5;201m"
#define EXT_202 "\x1b[38;5;202m"
#define EXT_203 "\x1b[38;5;203m"
#define EXT_204 "\x1b[38;5;204m"
#define EXT_205 "\x1b[38;5;205m"
#define EXT_206 "\x1b[38;5;206m"
#define EXT_207 "\x1b[38;5;207m"
#define EXT_208 "\x1b[38;5;208m"
#define EXT_209 "\x1b[38;5;209m"
#define EXT_210 "\x1b[38;5;210m"
#define EXT_211 "\x1b[38;5;211m"
#define EXT_212 "\x1b[38;5;212m"
#define EXT_213 "\x1b[38;5;213m"
#define EXT_214 "\x1b[38;5;214m"
#define EXT_215 "\x1b[38;5;215m"
#define EXT_216 "\x1b[38;5;216m"
#define EXT_217 "\x1b[38;5;217m"
#define EXT_218 "\x1b[38;5;218m"
#define EXT_219 "\x1b[38;5;219m"
#define EXT_220 "\x1b[38;5;220m"
#define EXT_221 "\x1b[38;5;221m"
#define EXT_222 "\x1b[38;5;222m"
#define EXT_223 "\x1b[38;5;223m"
#define EXT_224 "\x1b[38;5;224m"
#define EXT_225 "\x1b[38;5;225m"
#define EXT_226 "\x1b[38;5;226m"
#define EXT_227 "\x1b[38;5;227m"
#define EXT_228 "\x1b[38;5;228m"
#define EXT_229 "\x1b[38;5;229m"
#define EXT_230 "\x1b[38;5;230m"
#define EXT_231 "\x1b[38;5;231m"
#define EXT_232 "\x1b[38;5;232m"
#define EXT_233 "\x1b[38;5;233m"
#define EXT_234 "\x1b[38;5;234m"
#define EXT_235 "\x1b[38;5;235m"
#define EXT_236 "\x1b[38;5;236m"
#define EXT_237 "\x1b[38;5;237m"
#define EXT_238 "\x1b[38;5;238m"
#define EXT_239 "\x1b[38;5;239m"
#define EXT_240 "\x1b[38;5;240m"
#define EXT_241 "\x1b[38;5;241m"
#define EXT_242 "\x1b[38;5;242m"
#define EXT_243 "\x1b[38;5;243m"
#define EXT_244 "\x1b[38;5;244m"
#define EXT_245 "\x1b[38;5;245m"
#define EXT_246 "\x1b[38;5;246m"
#define EXT_247 "\x1b[38;5;247m"
#define EXT_248 "\x1b[38;5;248m"
#define EXT_249 "\x1b[38;5;249m"
#define EXT_250 "\x1b[38;5;250m"
#define EXT_251 "\x1b[38;5;251m"
#define EXT_252 "\x1b[38;5;252m"
#define EXT_253 "\x1b[38;5;253m"
#define EXT_254 "\x1b[38;5;254m"
#define EXT_255 "\x1b[38;5;255m"
#define EXT_B_1 "\x1b[48;5;1m"
#define EXT_B_2 "\x1b[48;5;2m"
#define EXT_B_3 "\x1b[48;5;3m"
#define EXT_B_4 "\x1b[48;5;4m"
#define EXT_B_5 "\x1b[48;5;5m"
#define EXT_B_6 "\x1b[48;5;6m"
#define EXT_B_7 "\x1b[48;5;7m"
#define EXT_B_8 "\x1b[48;5;8m"
#define EXT_B_9 "\x1b[48;5;9m"
#define EXT_B_10 "\x1b[48;5;10m"
#define EXT_B_11 "\x1b[48;5;11m"
#define EXT_B_12 "\x1b[48;5;12m"
#define EXT_B_13 "\x1b[48;5;13m"
#define EXT_B_14 "\x1b[48;5;14m"
#define EXT_B_15 "\x1b[48;5;15m"
#define EXT_B_16 "\x1b[48;5;16m"
#define EXT_B_17 "\x1b[48;5;17m"
#define EXT_B_18 "\x1b[48;5;18m"
#define EXT_B_19 "\x1b[48;5;19m"
#define EXT_B_20 "\x1b[48;5;20m"
#define EXT_B_21 "\x1b[48;5;21m"
#define EXT_B_22 "\x1b[48;5;22m"
#define EXT_B_23 "\x1b[48;5;23m"
#define EXT_B_24 "\x1b[48;5;24m"
#define EXT_B_25 "\x1b[48;5;25m"
#define EXT_B_26 "\x1b[48;5;26m"
#define EXT_B_27 "\x1b[48;5;27m"
#define EXT_B_28 "\x1b[48;5;28m"
#define EXT_B_29 "\x1b[48;5;29m"
#define EXT_B_30 "\x1b[48;5;30m"
#define EXT_B_31 "\x1b[48;5;31m"
#define EXT_B_32 "\x1b[48;5;32m"
#define EXT_B_33 "\x1b[48;5;33m"
#define EXT_B_34 "\x1b[48;5;34m"
#define EXT_B_35 "\x1b[48;5;35m"
#define EXT_B_36 "\x1b[48;5;36m"
#define EXT_B_37 "\x1b[48;5;37m"
#define EXT_B_38 "\x1b[48;5;38m"
#define EXT_B_39 "\x1b[48;5;39m"
#define EXT_B_40 "\x1b[48;5;40m"
#define EXT_B_41 "\x1b[48;5;41m"
#define EXT_B_42 "\x1b[48;5;42m"
#define EXT_B_43 "\x1b[48;5;43m"
#define EXT_B_44 "\x1b[48;5;44m"
#define EXT_B_45 "\x1b[48;5;45m"
#define EXT_B_46 "\x1b[48;5;46m"
#define EXT_B_47 "\x1b[48;5;47m"
#define EXT_B_48 "\x1b[48;5;48m"
#define EXT_B_49 "\x1b[48;5;49m"
#define EXT_B_50 "\x1b[48;5;50m"
#define EXT_B_51 "\x1b[48;5;51m"
#define EXT_B_52 "\x1b[48;5;52m"
#define EXT_B_53 "\x1b[48;5;53m"
#define EXT_B_54 "\x1b[48;5;54m"
#define EXT_B_55 "\x1b[48;5;55m"
#define EXT_B_56 "\x1b[48;5;56m"
#define EXT_B_57 "\x1b[48;5;57m"
#define EXT_B_58 "\x1b[48;5;58m"
#define EXT_B_59 "\x1b[48;5;59m"
#define EXT_B_60 "\x1b[48;5;60m"
#define EXT_B_61 "\x1b[48;5;61m"
#define EXT_B_62 "\x1b[48;5;62m"
#define EXT_B_63 "\x1b[48;5;63m"
#define EXT_B_64 "\x1b[48;5;64m"
#define EXT_B_65 "\x1b[48;5;65m"
#define EXT_B_66 "\x1b[48;5;66m"
#define EXT_B_67 "\x1b[48;5;67m"
#define EXT_B_68 "\x1b[48;5;68m"
#define EXT_B_69 "\x1b[48;5;69m"
#define EXT_B_70 "\x1b[48;5;70m"
#define EXT_B_71 "\x1b[48;5;71m"
#define EXT_B_72 "\x1b[48;5;72m"
#define EXT_B_73 "\x1b[48;5;73m"
#define EXT_B_74 "\x1b[48;5;74m"
#define EXT_B_75 "\x1b[48;5;75m"
#define EXT_B_76 "\x1b[48;5;76m"
#define EXT_B_77 "\x1b[48;5;77m"
#define EXT_B_78 "\x1b[48;5;78m"
#define EXT_B_79 "\x1b[48;5;79m"
#define EXT_B_80 "\x1b[48;5;80m"
#define EXT_B_81 "\x1b[48;5;81m"
#define EXT_B_82 "\x1b[48;5;82m"
#define EXT_B_83 "\x1b[48;5;83m"
#define EXT_B_84 "\x1b[48;5;84m"
#define EXT_B_85 "\x1b[48;5;85m"
#define EXT_B_86 "\x1b[48;5;86m"
#define EXT_B_87 "\x1b[48;5;87m"
#define EXT_B_88 "\x1b[48;5;88m"
#define EXT_B_89 "\x1b[48;5;89m"
#define EXT_B_90 "\x1b[48;5;90m"
#define EXT_B_91 "\x1b[48;5;91m"
#define EXT_B_92 "\x1b[48;5;92m"
#define EXT_B_93 "\x1b[48;5;93m"
#define EXT_B_94 "\x1b[48;5;94m"
#define EXT_B_95 "\x1b[48;5;95m"
#define EXT_B_96 "\x1b[48;5;96m"
#define EXT_B_97 "\x1b[48;5;97m"
#define EXT_B_98 "\x1b[48;5;98m"
#define EXT_B_99 "\x1b[48;5;99m"
#define EXT_B_100 "\x1b[48;5;100m"
#define EXT_B_101 "\x1b[48;5;101m"
#define EXT_B_102 "\x1b[48;5;102m"
#define EXT_B_103 "\x1b[48;5;103m"
#define EXT_B_104 "\x1b[48;5;104m"
#define EXT_B_105 "\x1b[48;5;105m"
#define EXT_B_106 "\x1b[48;5;106m"
#define EXT_B_107 "\x1b[48;5;107m"
#define EXT_B_108 "\x1b[48;5;108m"
#define EXT_B_109 "\x1b[48;5;109m"
#define EXT_B_110 "\x1b[48;5;110m"
#define EXT_B_111 "\x1b[48;5;111m"
#define EXT_B_112 "\x1b[48;5;112m"
#define EXT_B_113 "\x1b[48;5;113m"
#define EXT_B_114 "\x1b[48;5;114m"
#define EXT_B_115 "\x1b[48;5;115m"
#define EXT_B_116 "\x1b[48;5;116m"
#define EXT_B_117 "\x1b[48;5;117m"
#define EXT_B_118 "\x1b[48;5;118m"
#define EXT_B_119 "\x1b[48;5;119m"
#define EXT_B_120 "\x1b[48;5;120m"
#define EXT_B_121 "\x1b[48;5;121m"
#define EXT_B_122 "\x1b[48;5;122m"
#define EXT_B_123 "\x1b[48;5;123m"
#define EXT_B_124 "\x1b[48;5;124m"
#define EXT_B_125 "\x1b[48;5;125m"
#define EXT_B_126 "\x1b[48;5;126m"
#define EXT_B_127 "\x1b[48;5;127m"
#define EXT_B_128 "\x1b[48;5;128m"
#define EXT_B_129 "\x1b[48;5;129m"
#define EXT_B_130 "\x1b[48;5;130m"
#define EXT_B_131 "\x1b[48;5;131m"
#define EXT_B_132 "\x1b[48;5;132m"
#define EXT_B_133 "\x1b[48;5;133m"
#define EXT_B_134 "\x1b[48;5;134m"
#define EXT_B_135 "\x1b[48;5;135m"
#define EXT_B_136 "\x1b[48;5;136m"
#define EXT_B_137 "\x1b[48;5;137m"
#define EXT_B_138 "\x1b[48;5;138m"
#define EXT_B_139 "\x1b[48;5;139m"
#define EXT_B_140 "\x1b[48;5;140m"
#define EXT_B_141 "\x1b[48;5;141m"
#define EXT_B_142 "\x1b[48;5;142m"
#define EXT_B_143 "\x1b[48;5;143m"
#define EXT_B_144 "\x1b[48;5;144m"
#define EXT_B_145 "\x1b[48;5;145m"
#define EXT_B_146 "\x1b[48;5;146m"
#define EXT_B_147 "\x1b[48;5;147m"
#define EXT_B_148 "\x1b[48;5;148m"
#define EXT_B_149 "\x1b[48;5;149m"
#define EXT_B_150 "\x1b[48;5;150m"
#define EXT_B_151 "\x1b[48;5;151m"
#define EXT_B_152 "\x1b[48;5;152m"
#define EXT_B_153 "\x1b[48;5;153m"
#define EXT_B_154 "\x1b[48;5;154m"
#define EXT_B_155 "\x1b[48;5;155m"
#define EXT_B_156 "\x1b[48;5;156m"
#define EXT_B_157 "\x1b[48;5;157m"
#define EXT_B_158 "\x1b[48;5;158m"
#define EXT_B_159 "\x1b[48;5;159m"
#define EXT_B_160 "\x1b[48;5;160m"
#define EXT_B_161 "\x1b[48;5;161m"
#define EXT_B_162 "\x1b[48;5;162m"
#define EXT_B_163 "\x1b[48;5;163m"
#define EXT_B_164 "\x1b[48;5;164m"
#define EXT_B_165 "\x1b[48;5;165m"
#define EXT_B_166 "\x1b[48;5;166m"
#define EXT_B_167 "\x1b[48;5;167m"
#define EXT_B_168 "\x1b[48;5;168m"
#define EXT_B_169 "\x1b[48;5;169m"
#define EXT_B_170 "\x1b[48;5;170m"
#define EXT_B_171 "\x1b[48;5;171m"
#define EXT_B_172 "\x1b[48;5;172m"
#define EXT_B_173 "\x1b[48;5;173m"
#define EXT_B_174 "\x1b[48;5;174m"
#define EXT_B_175 "\x1b[48;5;175m"
#define EXT_B_176 "\x1b[48;5;176m"
#define EXT_B_177 "\x1b[48;5;177m"
#define EXT_B_178 "\x1b[48;5;178m"
#define EXT_B_179 "\x1b[48;5;179m"
#define EXT_B_180 "\x1b[48;5;180m"
#define EXT_B_181 "\x1b[48;5;181m"
#define EXT_B_182 "\x1b[48;5;182m"
#define EXT_B_183 "\x1b[48;5;183m"
#define EXT_B_184 "\x1b[48;5;184m"
#define EXT_B_185 "\x1b[48;5;185m"
#define EXT_B_186 "\x1b[48;5;186m"
#define EXT_B_187 "\x1b[48;5;187m"
#define EXT_B_188 "\x1b[48;5;188m"
#define EXT_B_189 "\x1b[48;5;189m"
#define EXT_B_190 "\x1b[48;5;190m"
#define EXT_B_191 "\x1b[48;5;191m"
#define EXT_B_192 "\x1b[48;5;192m"
#define EXT_B_193 "\x1b[48;5;193m"
#define EXT_B_194 "\x1b[48;5;194m"
#define EXT_B_195 "\x1b[48;5;195m"
#define EXT_B_196 "\x1b[48;5;196m"
#define EXT_B_197 "\x1b[48;5;197m"
#define EXT_B_198 "\x1b[48;5;198m"
#define EXT_B_199 "\x1b[48;5;199m"
#define EXT_B_200 "\x1b[48;5;200m"
#define EXT_B_201 "\x1b[48;5;201m"
#define EXT_B_202 "\x1b[48;5;202m"
#define EXT_B_203 "\x1b[48;5;203m"
#define EXT_B_204 "\x1b[48;5;204m"
#define EXT_B_205 "\x1b[48;5;205m"
#define EXT_B_206 "\x1b[48;5;206m"
#define EXT_B_207 "\x1b[48;5;207m"
#define EXT_B_208 "\x1b[48;5;208m"
#define EXT_B_209 "\x1b[48;5;209m"
#define EXT_B_210 "\x1b[48;5;210m"
#define EXT_B_211 "\x1b[48;5;211m"
#define EXT_B_212 "\x1b[48;5;212m"
#define EXT_B_213 "\x1b[48;5;213m"
#define EXT_B_214 "\x1b[48;5;214m"
#define EXT_B_215 "\x1b[48;5;215m"
#define EXT_B_216 "\x1b[48;5;216m"
#define EXT_B_217 "\x1b[48;5;217m"
#define EXT_B_218 "\x1b[48;5;218m"
#define EXT_B_219 "\x1b[48;5;219m"
#define EXT_B_220 "\x1b[48;5;220m"
#define EXT_B_221 "\x1b[48;5;221m"
#define EXT_B_222 "\x1b[48;5;222m"
#define EXT_B_223 "\x1b[48;5;223m"
#define EXT_B_224 "\x1b[48;5;224m"
#define EXT_B_225 "\x1b[48;5;225m"
#define EXT_B_226 "\x1b[48;5;226m"
#define EXT_B_227 "\x1b[48;5;227m"
#define EXT_B_228 "\x1b[48;5;228m"
#define EXT_B_229 "\x1b[48;5;229m"
#define EXT_B_230 "\x1b[48;5;230m"
#define EXT_B_231 "\x1b[48;5;231m"
#define EXT_B_232 "\x1b[48;5;232m"
#define EXT_B_233 "\x1b[48;5;233m"
#define EXT_B_234 "\x1b[48;5;234m"
#define EXT_B_235 "\x1b[48;5;235m"
#define EXT_B_236 "\x1b[48;5;236m"
#define EXT_B_237 "\x1b[48;5;237m"
#define EXT_B_238 "\x1b[48;5;238m"
#define EXT_B_239 "\x1b[48;5;239m"
#define EXT_B_240 "\x1b[48;5;240m"
#define EXT_B_241 "\x1b[48;5;241m"
#define EXT_B_242 "\x1b[48;5;242m"
#define EXT_B_243 "\x1b[48;5;243m"
#define EXT_B_244 "\x1b[48;5;244m"
#define EXT_B_245 "\x1b[48;5;245m"
#define EXT_B_246 "\x1b[48;5;246m"
#define EXT_B_247 "\x1b[48;5;247m"
#define EXT_B_248 "\x1b[48;5;248m"
#define EXT_B_249 "\x1b[48;5;249m"
#define EXT_B_250 "\x1b[48;5;250m"
#define EXT_B_251 "\x1b[48;5;251m"
#define EXT_B_252 "\x1b[48;5;252m"
#define EXT_B_253 "\x1b[48;5;253m"
#define EXT_B_254 "\x1b[48;5;254m"
#define EXT_B_255 "\x1b[48;5;255m"




static mapping color_trans, attr_trans, terminal_trans;
mapping symbolic_trans;
static mapping translations;
static mapping player_trans;
static mapping mxp_trans;
static mapping ext_trans;

static void restore_me(void) {
   unguarded("restore_object", ANSI_DATA);
}

static void save_me(void) {
   unguarded("save_object", ANSI_DATA);
}

void setup(void) {
   mapping tmp;

   if (!player_trans) {
      player_trans = ([]);
   }

   color_trans = ([
      "BLACK" : BLACK,
      "GREY" : GREY,
      "RED" : RED,
      "GREEN" : GREEN,
      "ORANGE" : ORANGE,
      "YELLOW" : YELLOW,
      "BLUE" : BLUE,
      "MAGENTA" : MAGENTA,
      "CYAN" : CYAN,
      "WHITE" : WHITE,
      "B_BLACK" : B_BLACK,
      "B_RED" : B_RED,
      "B_GREEN" : B_GREEN,
      "B_ORANGE" : B_ORANGE,
      "B_YELLOW" : B_YELLOW,
      "B_BLUE" : B_BLUE,
      "B_MAGENTA" : B_MAGENTA,
      "B_CYAN" : B_CYAN,
      "B_WHITE" : B_WHITE,
      "HRED" : HRED,
      "HGREEN" : HGREEN,
      "HBLUE" : HBLUE,
      "HMAGENTA" : HMAGENTA,
      "HCYAN" : HCYAN,
      "HWHITE" : HWHITE,
   ]);

   attr_trans = ([
      "RESET" : RESET,
      "BOLD" : BOLD,
      "BOLD_OFF" : BOLD_OFF,
      "ITALIC" : ITALIC,
      "UNDERLINE" : UNDERLINE,
      "FLASH" : FLASH,
      "REVERSE" : REVERSE,
   ]);

   terminal_trans = ([
      "CURS_UP" : CURS_UP,
      "CURS_DOWN" : CURS_DOWN,
      "CURS_RIGHT" : CURS_RIGHT,
      "CURS_LEFT" : CURS_LEFT,
      "CLEARLINE" : CLEARLINE,
      "INITTERM" : INITTERM,
      "ENDTERM" : ENDTERM,
      "SAVE" : SAVE,
      "RESTORE" : RESTORE,
      "HOME" : HOME,
   ]);

   mxp_trans = ([
      "MXP_OPEN" : MXP_OPEN,
      "MXP_SECURE" : MXP_SECURE,
      "MXP_LOCKED" : MXP_LOCKED,
      "MXP_RESET" : MXP_RESET,
      "MXP_TSM" : MXP_TSM,
      "MXP_LOM" : MXP_LOM,
      "MXP_LSM" : MXP_LSM,
      "MXP_LLM" : MXP_LLM,
      "MXP_ROOM_NAME" : MXP_ROOM_NAME,
      "MXP_ROOM_DESC" : MXP_ROOM_DESC,
      "MXP_ROOM_EXITS" : MXP_ROOM_EXITS,
   ]);

   ext_trans = ([
      "EXT_1" : EXT_1,
      "EXT_2" : EXT_2,
      "EXT_3" : EXT_3,
      "EXT_4" : EXT_4,
      "EXT_5" : EXT_5,
      "EXT_6" : EXT_6,
      "EXT_7" : EXT_7,
      "EXT_8" : EXT_8,
      "EXT_9" : EXT_9,
      "EXT_10" : EXT_10,
      "EXT_11" : EXT_11,
      "EXT_12" : EXT_12,
      "EXT_13" : EXT_13,
      "EXT_14" : EXT_14,
      "EXT_15" : EXT_15,
      "EXT_16" : EXT_16,
      "EXT_17" : EXT_17,
      "EXT_18" : EXT_18,
      "EXT_19" : EXT_19,
      "EXT_20" : EXT_20,
      "EXT_21" : EXT_21,
      "EXT_22" : EXT_22,
      "EXT_23" : EXT_23,
      "EXT_24" : EXT_24,
      "EXT_25" : EXT_25,
      "EXT_26" : EXT_26,
      "EXT_27" : EXT_27,
      "EXT_28" : EXT_28,
      "EXT_29" : EXT_29,
      "EXT_30" : EXT_30,
      "EXT_31" : EXT_31,
      "EXT_32" : EXT_32,
      "EXT_33" : EXT_33,
      "EXT_34" : EXT_34,
      "EXT_35" : EXT_35,
      "EXT_36" : EXT_36,
      "EXT_37" : EXT_37,
      "EXT_38" : EXT_38,
      "EXT_39" : EXT_39,
      "EXT_40" : EXT_40,
      "EXT_41" : EXT_41,
      "EXT_42" : EXT_42,
      "EXT_43" : EXT_43,
      "EXT_44" : EXT_44,
      "EXT_45" : EXT_45,
      "EXT_46" : EXT_46,
      "EXT_47" : EXT_47,
      "EXT_48" : EXT_48,
      "EXT_49" : EXT_49,
      "EXT_50" : EXT_50,
      "EXT_51" : EXT_51,
      "EXT_52" : EXT_52,
      "EXT_53" : EXT_53,
      "EXT_54" : EXT_54,
      "EXT_55" : EXT_55,
      "EXT_56" : EXT_56,
      "EXT_57" : EXT_57,
      "EXT_58" : EXT_58,
      "EXT_59" : EXT_59,
      "EXT_60" : EXT_60,
      "EXT_61" : EXT_61,
      "EXT_62" : EXT_62,
      "EXT_63" : EXT_63,
      "EXT_64" : EXT_64,
      "EXT_65" : EXT_65,
      "EXT_66" : EXT_66,
      "EXT_67" : EXT_67,
      "EXT_68" : EXT_68,
      "EXT_69" : EXT_69,
      "EXT_70" : EXT_70,
      "EXT_71" : EXT_71,
      "EXT_72" : EXT_72,
      "EXT_73" : EXT_73,
      "EXT_74" : EXT_74,
      "EXT_75" : EXT_75,
      "EXT_76" : EXT_76,
      "EXT_77" : EXT_77,
      "EXT_78" : EXT_78,
      "EXT_79" : EXT_79,
      "EXT_80" : EXT_80,
      "EXT_81" : EXT_81,
      "EXT_82" : EXT_82,
      "EXT_83" : EXT_83,
      "EXT_84" : EXT_84,
      "EXT_85" : EXT_85,
      "EXT_86" : EXT_86,
      "EXT_87" : EXT_87,
      "EXT_88" : EXT_88,
      "EXT_89" : EXT_89,
      "EXT_90" : EXT_90,
      "EXT_91" : EXT_91,
      "EXT_92" : EXT_92,
      "EXT_93" : EXT_93,
      "EXT_94" : EXT_94,
      "EXT_95" : EXT_95,
      "EXT_96" : EXT_96,
      "EXT_97" : EXT_97,
      "EXT_98" : EXT_98,
      "EXT_99" : EXT_99,
      "EXT_100" : EXT_100,
      "EXT_101" : EXT_101,
      "EXT_102" : EXT_102,
      "EXT_103" : EXT_103,
      "EXT_104" : EXT_104,
      "EXT_105" : EXT_105,
      "EXT_106" : EXT_106,
      "EXT_107" : EXT_107,
      "EXT_108" : EXT_108,
      "EXT_109" : EXT_109,
      "EXT_110" : EXT_110,
      "EXT_111" : EXT_111,
      "EXT_112" : EXT_112,
      "EXT_113" : EXT_113,
      "EXT_114" : EXT_114,
      "EXT_115" : EXT_115,
      "EXT_116" : EXT_116,
      "EXT_117" : EXT_117,
      "EXT_118" : EXT_118,
      "EXT_119" : EXT_119,
      "EXT_120" : EXT_120,
      "EXT_121" : EXT_121,
      "EXT_122" : EXT_122,
      "EXT_123" : EXT_123,
      "EXT_124" : EXT_124,
      "EXT_125" : EXT_125,
      "EXT_126" : EXT_126,
      "EXT_127" : EXT_127,
      "EXT_128" : EXT_128,
      "EXT_129" : EXT_129,
      "EXT_130" : EXT_130,
      "EXT_131" : EXT_131,
      "EXT_132" : EXT_132,
      "EXT_133" : EXT_133,
      "EXT_134" : EXT_134,
      "EXT_135" : EXT_135,
      "EXT_136" : EXT_136,
      "EXT_137" : EXT_137,
      "EXT_138" : EXT_138,
      "EXT_139" : EXT_139,
      "EXT_140" : EXT_140,
      "EXT_141" : EXT_141,
      "EXT_142" : EXT_142,
      "EXT_143" : EXT_143,
      "EXT_144" : EXT_144,
      "EXT_145" : EXT_145,
      "EXT_146" : EXT_146,
      "EXT_147" : EXT_147,
      "EXT_148" : EXT_148,
      "EXT_149" : EXT_149,
      "EXT_150" : EXT_150,
      "EXT_151" : EXT_151,
      "EXT_152" : EXT_152,
      "EXT_153" : EXT_153,
      "EXT_154" : EXT_154,
      "EXT_155" : EXT_155,
      "EXT_156" : EXT_156,
      "EXT_157" : EXT_157,
      "EXT_158" : EXT_158,
      "EXT_159" : EXT_159,
      "EXT_160" : EXT_160,
      "EXT_161" : EXT_161,
      "EXT_162" : EXT_162,
      "EXT_163" : EXT_163,
      "EXT_164" : EXT_164,
      "EXT_165" : EXT_165,
      "EXT_166" : EXT_166,
      "EXT_167" : EXT_167,
      "EXT_168" : EXT_168,
      "EXT_169" : EXT_169,
      "EXT_170" : EXT_170,
      "EXT_171" : EXT_171,
      "EXT_172" : EXT_172,
      "EXT_173" : EXT_173,
      "EXT_174" : EXT_174,
      "EXT_175" : EXT_175,
      "EXT_176" : EXT_176,
      "EXT_177" : EXT_177,
      "EXT_178" : EXT_178,
      "EXT_179" : EXT_179,
      "EXT_180" : EXT_180,
      "EXT_181" : EXT_181,
      "EXT_182" : EXT_182,
      "EXT_183" : EXT_183,
      "EXT_184" : EXT_184,
      "EXT_185" : EXT_185,
      "EXT_186" : EXT_186,
      "EXT_187" : EXT_187,
      "EXT_188" : EXT_188,
      "EXT_189" : EXT_189,
      "EXT_190" : EXT_190,
      "EXT_191" : EXT_191,
      "EXT_192" : EXT_192,
      "EXT_193" : EXT_193,
      "EXT_194" : EXT_194,
      "EXT_195" : EXT_195,
      "EXT_196" : EXT_196,
      "EXT_197" : EXT_197,
      "EXT_198" : EXT_198,
      "EXT_199" : EXT_199,
      "EXT_200" : EXT_200,
      "EXT_201" : EXT_201,
      "EXT_202" : EXT_202,
      "EXT_203" : EXT_203,
      "EXT_204" : EXT_204,
      "EXT_205" : EXT_205,
      "EXT_206" : EXT_206,
      "EXT_207" : EXT_207,
      "EXT_208" : EXT_208,
      "EXT_209" : EXT_209,
      "EXT_210" : EXT_210,
      "EXT_211" : EXT_211,
      "EXT_212" : EXT_212,
      "EXT_213" : EXT_213,
      "EXT_214" : EXT_214,
      "EXT_215" : EXT_215,
      "EXT_216" : EXT_216,
      "EXT_217" : EXT_217,
      "EXT_218" : EXT_218,
      "EXT_219" : EXT_219,
      "EXT_220" : EXT_220,
      "EXT_221" : EXT_221,
      "EXT_222" : EXT_222,
      "EXT_223" : EXT_223,
      "EXT_224" : EXT_224,
      "EXT_225" : EXT_225,
      "EXT_226" : EXT_226,
      "EXT_227" : EXT_227,
      "EXT_228" : EXT_228,
      "EXT_229" : EXT_229,
      "EXT_230" : EXT_230,
      "EXT_231" : EXT_231,
      "EXT_232" : EXT_232,
      "EXT_233" : EXT_233,
      "EXT_234" : EXT_234,
      "EXT_235" : EXT_235,
      "EXT_236" : EXT_236,
      "EXT_237" : EXT_237,
      "EXT_238" : EXT_238,
      "EXT_239" : EXT_239,
      "EXT_240" : EXT_240,
      "EXT_241" : EXT_241,
      "EXT_242" : EXT_242,
      "EXT_243" : EXT_243,
      "EXT_244" : EXT_244,
      "EXT_245" : EXT_245,
      "EXT_246" : EXT_246,
      "EXT_247" : EXT_247,
      "EXT_248" : EXT_248,
      "EXT_249" : EXT_249,
      "EXT_250" : EXT_250,
      "EXT_251" : EXT_251,
      "EXT_252" : EXT_252,
      "EXT_253" : EXT_253,
      "EXT_254" : EXT_254,
      "EXT_255" : EXT_255,
            "EXT_B_1" : EXT_B_1,
      "EXT_B_2" : EXT_B_2,
      "EXT_B_3" : EXT_B_3,
      "EXT_B_4" : EXT_B_4,
      "EXT_B_5" : EXT_B_5,
      "EXT_B_6" : EXT_B_6,
      "EXT_B_7" : EXT_B_7,
      "EXT_B_8" : EXT_B_8,
      "EXT_B_9" : EXT_B_9,
      "EXT_B_10" : EXT_B_10,
      "EXT_B_11" : EXT_B_11,
      "EXT_B_12" : EXT_B_12,
      "EXT_B_13" : EXT_B_13,
      "EXT_B_14" : EXT_B_14,
      "EXT_B_15" : EXT_B_15,
      "EXT_B_16" : EXT_B_16,
      "EXT_B_17" : EXT_B_17,
      "EXT_B_18" : EXT_B_18,
      "EXT_B_19" : EXT_B_19,
      "EXT_B_20" : EXT_B_20,
      "EXT_B_21" : EXT_B_21,
      "EXT_B_22" : EXT_B_22,
      "EXT_B_23" : EXT_B_23,
      "EXT_B_24" : EXT_B_24,
      "EXT_B_25" : EXT_B_25,
      "EXT_B_26" : EXT_B_26,
      "EXT_B_27" : EXT_B_27,
      "EXT_B_28" : EXT_B_28,
      "EXT_B_29" : EXT_B_29,
      "EXT_B_30" : EXT_B_30,
      "EXT_B_31" : EXT_B_31,
      "EXT_B_32" : EXT_B_32,
      "EXT_B_33" : EXT_B_33,
      "EXT_B_34" : EXT_B_34,
      "EXT_B_35" : EXT_B_35,
      "EXT_B_36" : EXT_B_36,
      "EXT_B_37" : EXT_B_37,
      "EXT_B_38" : EXT_B_38,
      "EXT_B_39" : EXT_B_39,
      "EXT_B_40" : EXT_B_40,
      "EXT_B_41" : EXT_B_41,
      "EXT_B_42" : EXT_B_42,
      "EXT_B_43" : EXT_B_43,
      "EXT_B_44" : EXT_B_44,
      "EXT_B_45" : EXT_B_45,
      "EXT_B_46" : EXT_B_46,
      "EXT_B_47" : EXT_B_47,
      "EXT_B_48" : EXT_B_48,
      "EXT_B_49" : EXT_B_49,
      "EXT_B_50" : EXT_B_50,
      "EXT_B_51" : EXT_B_51,
      "EXT_B_52" : EXT_B_52,
      "EXT_B_53" : EXT_B_53,
      "EXT_B_54" : EXT_B_54,
      "EXT_B_55" : EXT_B_55,
      "EXT_B_56" : EXT_B_56,
      "EXT_B_57" : EXT_B_57,
      "EXT_B_58" : EXT_B_58,
      "EXT_B_59" : EXT_B_59,
      "EXT_B_60" : EXT_B_60,
      "EXT_B_61" : EXT_B_61,
      "EXT_B_62" : EXT_B_62,
      "EXT_B_63" : EXT_B_63,
      "EXT_B_64" : EXT_B_64,
      "EXT_B_65" : EXT_B_65,
      "EXT_B_66" : EXT_B_66,
      "EXT_B_67" : EXT_B_67,
      "EXT_B_68" : EXT_B_68,
      "EXT_B_69" : EXT_B_69,
      "EXT_B_70" : EXT_B_70,
      "EXT_B_71" : EXT_B_71,
      "EXT_B_72" : EXT_B_72,
      "EXT_B_73" : EXT_B_73,
      "EXT_B_74" : EXT_B_74,
      "EXT_B_75" : EXT_B_75,
      "EXT_B_76" : EXT_B_76,
      "EXT_B_77" : EXT_B_77,
      "EXT_B_78" : EXT_B_78,
      "EXT_B_79" : EXT_B_79,
      "EXT_B_80" : EXT_B_80,
      "EXT_B_81" : EXT_B_81,
      "EXT_B_82" : EXT_B_82,
      "EXT_B_83" : EXT_B_83,
      "EXT_B_84" : EXT_B_84,
      "EXT_B_85" : EXT_B_85,
      "EXT_B_86" : EXT_B_86,
      "EXT_B_87" : EXT_B_87,
      "EXT_B_88" : EXT_B_88,
      "EXT_B_89" : EXT_B_89,
      "EXT_B_90" : EXT_B_90,
      "EXT_B_91" : EXT_B_91,
      "EXT_B_92" : EXT_B_92,
      "EXT_B_93" : EXT_B_93,
      "EXT_B_94" : EXT_B_94,
      "EXT_B_95" : EXT_B_95,
      "EXT_B_96" : EXT_B_96,
      "EXT_B_97" : EXT_B_97,
      "EXT_B_98" : EXT_B_98,
      "EXT_B_99" : EXT_B_99,
      "EXT_B_100" : EXT_B_100,
      "EXT_B_101" : EXT_B_101,
      "EXT_B_102" : EXT_B_102,
      "EXT_B_103" : EXT_B_103,
      "EXT_B_104" : EXT_B_104,
      "EXT_B_105" : EXT_B_105,
      "EXT_B_106" : EXT_B_106,
      "EXT_B_107" : EXT_B_107,
      "EXT_B_108" : EXT_B_108,
      "EXT_B_109" : EXT_B_109,
      "EXT_B_110" : EXT_B_110,
      "EXT_B_111" : EXT_B_111,
      "EXT_B_112" : EXT_B_112,
      "EXT_B_113" : EXT_B_113,
      "EXT_B_114" : EXT_B_114,
      "EXT_B_115" : EXT_B_115,
      "EXT_B_116" : EXT_B_116,
      "EXT_B_117" : EXT_B_117,
      "EXT_B_118" : EXT_B_118,
      "EXT_B_119" : EXT_B_119,
      "EXT_B_120" : EXT_B_120,
      "EXT_B_121" : EXT_B_121,
      "EXT_B_122" : EXT_B_122,
      "EXT_B_123" : EXT_B_123,
      "EXT_B_124" : EXT_B_124,
      "EXT_B_125" : EXT_B_125,
      "EXT_B_126" : EXT_B_126,
      "EXT_B_127" : EXT_B_127,
      "EXT_B_128" : EXT_B_128,
      "EXT_B_129" : EXT_B_129,
      "EXT_B_130" : EXT_B_130,
      "EXT_B_131" : EXT_B_131,
      "EXT_B_132" : EXT_B_132,
      "EXT_B_133" : EXT_B_133,
      "EXT_B_134" : EXT_B_134,
      "EXT_B_135" : EXT_B_135,
      "EXT_B_136" : EXT_B_136,
      "EXT_B_137" : EXT_B_137,
      "EXT_B_138" : EXT_B_138,
      "EXT_B_139" : EXT_B_139,
      "EXT_B_140" : EXT_B_140,
      "EXT_B_141" : EXT_B_141,
      "EXT_B_142" : EXT_B_142,
      "EXT_B_143" : EXT_B_143,
      "EXT_B_144" : EXT_B_144,
      "EXT_B_145" : EXT_B_145,
      "EXT_B_146" : EXT_B_146,
      "EXT_B_147" : EXT_B_147,
      "EXT_B_148" : EXT_B_148,
      "EXT_B_149" : EXT_B_149,
      "EXT_B_150" : EXT_B_150,
      "EXT_B_151" : EXT_B_151,
      "EXT_B_152" : EXT_B_152,
      "EXT_B_153" : EXT_B_153,
      "EXT_B_154" : EXT_B_154,
      "EXT_B_155" : EXT_B_155,
      "EXT_B_156" : EXT_B_156,
      "EXT_B_157" : EXT_B_157,
      "EXT_B_158" : EXT_B_158,
      "EXT_B_159" : EXT_B_159,
      "EXT_B_160" : EXT_B_160,
      "EXT_B_161" : EXT_B_161,
      "EXT_B_162" : EXT_B_162,
      "EXT_B_163" : EXT_B_163,
      "EXT_B_164" : EXT_B_164,
      "EXT_B_165" : EXT_B_165,
      "EXT_B_166" : EXT_B_166,
      "EXT_B_167" : EXT_B_167,
      "EXT_B_168" : EXT_B_168,
      "EXT_B_169" : EXT_B_169,
      "EXT_B_170" : EXT_B_170,
      "EXT_B_171" : EXT_B_171,
      "EXT_B_172" : EXT_B_172,
      "EXT_B_173" : EXT_B_173,
      "EXT_B_174" : EXT_B_174,
      "EXT_B_175" : EXT_B_175,
      "EXT_B_176" : EXT_B_176,
      "EXT_B_177" : EXT_B_177,
      "EXT_B_178" : EXT_B_178,
      "EXT_B_179" : EXT_B_179,
      "EXT_B_180" : EXT_B_180,
      "EXT_B_181" : EXT_B_181,
      "EXT_B_182" : EXT_B_182,
      "EXT_B_183" : EXT_B_183,
      "EXT_B_184" : EXT_B_184,
      "EXT_B_185" : EXT_B_185,
      "EXT_B_186" : EXT_B_186,
      "EXT_B_187" : EXT_B_187,
      "EXT_B_188" : EXT_B_188,
      "EXT_B_189" : EXT_B_189,
      "EXT_B_190" : EXT_B_190,
      "EXT_B_191" : EXT_B_191,
      "EXT_B_192" : EXT_B_192,
      "EXT_B_193" : EXT_B_193,
      "EXT_B_194" : EXT_B_194,
      "EXT_B_195" : EXT_B_195,
      "EXT_B_196" : EXT_B_196,
      "EXT_B_197" : EXT_B_197,
      "EXT_B_198" : EXT_B_198,
      "EXT_B_199" : EXT_B_199,
      "EXT_B_200" : EXT_B_200,
      "EXT_B_201" : EXT_B_201,
      "EXT_B_202" : EXT_B_202,
      "EXT_B_203" : EXT_B_203,
      "EXT_B_204" : EXT_B_204,
      "EXT_B_205" : EXT_B_205,
      "EXT_B_206" : EXT_B_206,
      "EXT_B_207" : EXT_B_207,
      "EXT_B_208" : EXT_B_208,
      "EXT_B_209" : EXT_B_209,
      "EXT_B_210" : EXT_B_210,
      "EXT_B_211" : EXT_B_211,
      "EXT_B_212" : EXT_B_212,
      "EXT_B_213" : EXT_B_213,
      "EXT_B_214" : EXT_B_214,
      "EXT_B_215" : EXT_B_215,
      "EXT_B_216" : EXT_B_216,
      "EXT_B_217" : EXT_B_217,
      "EXT_B_218" : EXT_B_218,
      "EXT_B_219" : EXT_B_219,
      "EXT_B_220" : EXT_B_220,
      "EXT_B_221" : EXT_B_221,
      "EXT_B_222" : EXT_B_222,
      "EXT_B_223" : EXT_B_223,
      "EXT_B_224" : EXT_B_224,
      "EXT_B_225" : EXT_B_225,
      "EXT_B_226" : EXT_B_226,
      "EXT_B_227" : EXT_B_227,
      "EXT_B_228" : EXT_B_228,
      "EXT_B_229" : EXT_B_229,
      "EXT_B_230" : EXT_B_230,
      "EXT_B_231" : EXT_B_231,
      "EXT_B_232" : EXT_B_232,
      "EXT_B_233" : EXT_B_233,
      "EXT_B_234" : EXT_B_234,
      "EXT_B_235" : EXT_B_235,
      "EXT_B_236" : EXT_B_236,
      "EXT_B_237" : EXT_B_237,
      "EXT_B_238" : EXT_B_238,
      "EXT_B_239" : EXT_B_239,
      "EXT_B_240" : EXT_B_240,
      "EXT_B_241" : EXT_B_241,
      "EXT_B_242" : EXT_B_242,
      "EXT_B_243" : EXT_B_243,
      "EXT_B_244" : EXT_B_244,
      "EXT_B_245" : EXT_B_245,
      "EXT_B_246" : EXT_B_246,
      "EXT_B_247" : EXT_B_247,
      "EXT_B_248" : EXT_B_248,
      "EXT_B_249" : EXT_B_249,
      "EXT_B_250" : EXT_B_250,
      "EXT_B_251" : EXT_B_251,
      "EXT_B_252" : EXT_B_252,
      "EXT_B_253" : EXT_B_253,
      "EXT_B_254" : EXT_B_254,
      "EXT_B_255" : EXT_B_255,

   ]);


   tmp = ([
      "CHAN_NAME" : BLUE,
      "CHAN_DATE" : CYAN,
      "CHAN_TEXT" : RESET,
      "CHAN_USER" : RESET,
      "TELL_FROM" : MAGENTA,
      "TELL_TO" : MAGENTA,
      "ROOM_NAME" : GREEN,
      "ROOM_DESC" : RESET,
      "ROOM_EXIT" : CYAN,
      "OBJ_ID" : WHITE,
      "OBJ_ADJ" : WHITE,
      "OBJ_BRIEF" : WHITE,
      "NPC_FRIENDLY" : GREEN,
      "PLAYER" : YELLOW,
      "NPC_HOSTILE" : RED,
      "MENU_TEXT" : CYAN,
      "MENU_HILITE" : GREEN,
      "MENU_KEY" : YELLOW,
      "MENU_DECORATE" : HWHITE,
   ]);

   restore_me();

   if (!symbolic_trans) {
      symbolic_trans = tmp;
   } else {
      symbolic_trans = tmp + symbolic_trans;
   }

   translations = color_trans + attr_trans + terminal_trans + mxp_trans + ext_trans;
}

void create(void) {
   setup();
}

string strip_colors(string str) {
   string msg, *tmp;
   int i, sz;

   tmp = explode(str, "%^");

   sz = sizeof(tmp);
   for (i = 0; i < sz; i++) {
      if (translations[tmp[i]] || symbolic_trans[tmp[i]]) {
         tmp[i] = "";
      }
   }
   msg = implode(tmp, "");
   return msg;
}

static string _parse_colors(string str, int curdepth, mapping cache,
   object player) {
   string msg, *tmp;
   mixed *ind, *sym;
   int i;

#ifndef SYS_COLOR
   return strip_colors(str);
#endif

   if (!player_trans) {
      player_trans = ([]);
   }

   tmp = explode(str, "%^");

   rlimits(MAX_DEPTH; MAX_TICKS) {
      for (i = 0; i < sizeof(tmp); i++) {
         if (cache[tmp[i]]) {
            tmp[i] = cache[tmp[i]];
         } else {
            string tag;
            tag = tmp[i];
            if (translations[tmp[i]]) {
               tmp[i] = translations[tmp[i]];
            } else if (curdepth < MAX_RECURSION) {
               if (player && player_trans[player] &&
                  player_trans[player][tmp[i]]) {
                  tmp[i] =
                     _parse_colors(player_trans[player][tmp[i]], curdepth + 1,
                     cache, player);
               } else if (symbolic_trans[tmp[i]]) {
                  tmp[i] =
                     _parse_colors(symbolic_trans[tmp[i]], curdepth + 1, cache,
                     player);
               }
            }
            if (map_sizeof(cache) < MAX_ARRAY_SIZE / 2 && tag != tmp[i]) {
               cache[tag] = tmp[i];
            }
         }
      }
   }

   msg = implode(tmp, "");
   return msg;
}

string parse_colors(string str, varargs int curdepth) {
   mapping cacheroot, cache;
   object player;

   player = previous_object()->query_player();
   if (!player) {
      player = this_player();
   }
   if (player && player->base_name() != PLAYER_OB) {
      player = nil;
   }

/*
 * This makes use of the fact that mappings are references, hence
 * once the mappings are setup, there is no need to store them to
 * the tls when things change.
 */
   cacheroot = get_tlvar(CACHE);
   if (!cacheroot) {
      cacheroot = ([]);
      set_tlvar(CACHE, cacheroot);
   }

   if (player) {
      cache = cacheroot[player];
      if (!cache) {
         cache = ([]);
         cacheroot[player] = cache;
      }
   } else {
      cache = cacheroot["base"];
      if (!cache) {
         cache = ([]);
         cacheroot["base"] = cache;
      }
   }
   return _parse_colors(str, 0, cache, player);
}

string color_table_chunk(mapping m, int codes) {
   int i, j, sz, pad;
   mixed *ind, *val;
   string msg, tokenized, reset;

   sz = map_sizeof(m);
   ind = map_indices(m);
   /* val = map_values(m); */
   msg = "";

   if (codes) {
      reset = "%^RESET%^";
   } else {
      reset = "";
   }

   for (i = 0; i < sz; i++) {

      if (codes) {
         tokenized = "%^" + ind[i] + "%^";
      } else {
         tokenized = "";
      }

      pad = 16 - strlen(ind[i]) - 1;
      /* Bizzare... if I remove the space in the line below, I get nothing! */
      msg += tokenized + " " + ind[i];
      for (j = 0; j < pad; j++) {
         msg += " ";
      }
      msg += reset;
      if (i % 4 == 3) {
         msg += "\n";
      } else {
         msg += " ";
      }
   }

   if (sz % 4 != 0) {
      msg += "\n";
   }

   return msg;
}

string color_table(void) {
   string msg;

   msg = "Colors:\n";
   msg += color_table_chunk(color_trans, 1);
   msg += "\nAttributes:\n";
   msg += color_table_chunk(attr_trans, 1);
/*
  msg += "\nTerminal:\n";
  msg += color_table_chunk( terminal_trans, 0 );
*/
   msg += "\nSymbolic:\n";
   msg += color_table_chunk(symbolic_trans, 1);
   return msg;
}

/*
 * My thoughts here were to not only allow simple named colours
 * by passing an array of normal colour tokens (IE: BOLD ITALIC BLUE),
 * but to eventually allow arbitrary text as well.
 * However, things like setting FOO = %^BOLD%^Hello%^FOO%^There would
 * be Bad(TM).
 */
void ansi_set_color(string name, string * symbols) {
   string tmp;
   mixed *ind, *sym;
   int i, sz;

   if (query_admin(this_player()->query_name()) != 1) {
      write("Access denied.\n");
      return;
   }

   name = uppercase(name);
   ind = map_indices(translations);
   sym = map_indices(symbolic_trans);
   tmp = "";

   sz = sizeof(symbols);
   for (i = 0; i < sz; i++) {
      if (strstr("%^", symbols[i]) == -1) {
         symbols[i] = uppercase(symbols[i]);
         if (!translations[symbols[i]] && !symbolic_trans[symbols[i]]) {
            /* Each symbol must resolve to a pre-defined token */
            write("Symbolic color tokens must be composed of only valid " +
               "base color tokens or pre-existing custom tokens.\n");
            return;
         }
         tmp += "%^" + symbols[i] + "%^";
      } else {
         write("Symbolic color tokens cannot (YET) contain custom tokens\n");
         return;
      }
   }

   symbolic_trans[name] = tmp;
   out_unmod(name + " is now " + tmp + "\n");
   save_me();
}

void ansi_remove_color(string name) {
   mixed *ind;

   if (query_admin(this_player()->query_name()) != 1) {
      write("Access denied.\n");
      return;
   }

   name = uppercase(name);
   ind = map_indices(symbolic_trans);

   if (!symbolic_trans[name]) {
      write(name + " is not currently a symbolic color!\n");
      return;
   }

   symbolic_trans[name] = nil;
   write(name + " is no longer a valid color.\n");
   save_me();
}

string query_base_symbol(string str) {
   return translations[str];
}

string query_custom_symbol(string str) {
   return symbolic_trans[str];
}

string query_any_symbol(string str) {
   if (translations[str]) {
      return translations[str];
   }
   if (symbolic_trans[str]) {
      return symbolic_trans[str];
   }
}

void set_player_translations(mapping trans) {
   object player;

   player = (object PLAYER_OB) previous_object();

   if (!player_trans) {
      player_trans = ([player:trans]);
   } else {
      player_trans[player] = trans;
   }
}

/*
 * Returns 0 on no error
 *         1 on too deep recursion
 *         2 on self referring tag
 */
int check_recursion(string tag, string value) {
   int count;
   mapping seen;
   object player;

   player = this_player();

   tag = replace_string(tag, "%^", "");

   while (count < MAX_RECURSION) {

      count++;
      value = replace_string(value, "%^", "");

      if (tag == value) {
         return 2;
      }

      value = replace_string(value, "%^", "");

      if (player && player_trans[player] && player_trans[player][value]) {
         value = player_trans[player][value];
      } else if (symbolic_trans[value]) {
         value = symbolic_trans[value];
      } else {
         return 0;
      }
   }
   return 1;
}

void upgraded(void) {
   setup();
}
