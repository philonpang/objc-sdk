//
//  AVSearchSortBuilder.h
//  paas
//
//  Created by yang chaozhong on 6/13/14.
//  Copyright (c) 2014 AVOS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 *  应用搜索的排序对象产生器
 */
@interface AVSearchSortBuilder : NSObject

@property (nonatomic, strong, readonly) NSMutableArray *sortFields;

/*!
 *  新建 AVSearchSortBuilder 实例
 *  @return AVSearchSortBuilder 实例
 */
+ (instancetype)newBuilder;

/*!
 *  按照key升序排序
 *  @param key 排序的key
 *  @param mode 数组或者多值字段的排序模式，min表示取最小值，max取最大值，sum取综合，avg取平均值，默认值是avg
 *  @param missing 当搜索匹配的文档没有排序的key的时候，设置本选项决定文档放在开头还是末尾，取值是"last"或者"first"，默认是"last"表示在末尾
 */
- (void)orderByAscending:(NSString *)key withMode:(NSString *)mode andMissing:(NSString *)missing;

/*!
 *  @see orderByAscending:withMode:andMissing:
 */
- (void)orderByAscending:(NSString *)key withMode:(NSString *)mode;

/*!
 *  @see orderByAscending:withMode:andMissing:
 */
- (void)orderByAscending:(NSString *)key;

/*!
 * 按照key降序排序
 *
 *  @param key 排序的key
 *  @param mode 数组或者多值字段的排序模式，min表示取最小值，max取最大值，sum取综合，avg取平均值，默认值是avg。
 *  @param missing 当搜索匹配的文档没有排序的key的时候，设置本选项决定文档放在开头还是末尾，取值是"last"或者"first"，默认是"last"表示在末尾。
 */
- (void)orderByDescending:(NSString *)key withMode:(NSString *)mode andMissing:(NSString *)missing;

/*!
 *  @see orderByDescending:withMode:andMissing:
 */
- (void)orderByDescending:(NSString *)key withMode:(NSString *)mode;

/*!
 *  @see orderByDescending:withMode:andMissing:
 */
- (void)orderByDescending:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
